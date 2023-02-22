import ROOT as r
import matplotlib.pyplot as plt

def fit_z_mass_distribution():
    # Create the workspace
    w = r.RooWorkspace("w")

    # Define the observable
    inv_mass = r.RooRealVar("inv_mass", "Invariant Mass (GeV)", 60, 120)

    # Load the histograms
    file_pass = r.TFile("passing_probe_histogram.root")
    hist_pass = file_pass.Get("passing_probe_histogram")

    file_fail = r.TFile("failing_probe_histogram.root")
    hist_fail = file_fail.Get("failing_probe_histogram")

    # Create a RooDataHist from the passing probe histogram
    data_pass = r.RooDataHist("data_pass", "Passing Probe Histogram", r.RooArgList(inv_mass), hist_pass)

    # Create a RooDataHist from the failing probe histogram
    data_fail = r.RooDataHist("data_fail", "Failing Probe Histogram", r.RooArgList(inv_mass), hist_fail)

    # Define the Z boson mass
    z_mass = 91.1876

    # Define the Breit-Wigner PDF for the Z boson peak
    bw_mean = r.RooRealVar("bw_mean", "Mean of Breit-Wigner", z_mass, 85, 95)
    bw_width = r.RooRealVar("bw_width", "Width of Breit-Wigner", 2.5, 0.1, 10)
    bw = r.RooBreitWigner("bw", "Breit-Wigner PDF", inv_mass, bw_mean, bw_width)

    # Define the Gaussian PDF for the resolution
    gauss_mean = r.RooRealVar("gauss_mean", "Mean of Gaussian", 0, -10, 10)
    gauss_width = r.RooRealVar("gauss_width", "Width of Gaussian", 2, 0.1, 10)
    gauss = r.RooGaussian("gauss", "Gaussian PDF", inv_mass, gauss_mean, gauss_width)

    # Convolve the Breit-Wigner and Gaussian PDFs to get the signal PDF
    signal = r.RooFFTConvPdf("signal", "Signal PDF", inv_mass, bw, gauss)

    # Create a histogram PDF from the passing probe data
    pdf_pass = r.RooHistPdf("pdf_pass", "Passing Probe PDF", r.RooArgSet(inv_mass), data_pass)

    # Create a histogram PDF from the failing probe data
    pdf_fail = r.RooHistPdf("pdf_fail", "Failing Probe PDF", r.RooArgSet(inv_mass), data_fail)

    # Define the total PDF as a sum of the signal, passing probe, and failing probe PDFs
    nsig = r.RooRealVar("nsig", "Number of Signal Events", 1000, 0, data_pass.numEntries()+data_fail.numEntries())
    npass = r.RooRealVar("npass", "Number of Passing Probe Events", data_pass.numEntries(), 0, data_pass.numEntries())
    nbkg_pass = r.RooRealVar("nbkg_pass", "Number of Background Events (Passing Probe)", 100, 0, data_pass.numEntries())

    pdf_total = r.RooAddPdf("pdf_total", "Total PDF", r.RooArgList(signal, pdf_pass, pdf_fail),
                            r.RooArgList(nsig, npass, nbkg_pass))

   

def plot_fit_result(fit_result, data, pdf, output_filename):
    # Plot the fit result
    x = r.RooRealVar("x", "x", 60, 120)
    frame = x.frame(r.RooFit.Title("Z Boson Invariant Mass Distribution"))
    data.plotOn(frame, r.RooFit.Name("data"))
    pdf.plotOn(frame, r.RooFit.Name("total"))

    # Plot the components of the total PDF separately
    pdf.plotOn(frame, r.RooFit.Components("signal"), r.RooFit.LineStyle(r.kDashed),
               r.RooFit.Name("signal"))
    pdf.plotOn(frame, r.RooFit.Components("pdf_pass"), r.RooFit.LineStyle(r.kDashed),
               r.RooFit.LineColor(r.kRed), r.RooFit.Name("passing probe"))
    pdf.plotOn(frame, r.RooFit.Components("pdf_fail"), r.RooFit.LineStyle(r.kDashed),
               r.RooFit.LineColor(r.kGreen), r.RooFit.Name("failing probe"))

    # Get the fit parameters and their errors
    fit_parameters = fit_result.floatParsFinal()
    parameter_names = [fit_parameters[i].GetName() for i in range(fit_parameters.getSize())]
    parameter_values = [fit_parameters[i].getVal() for i in range(fit_parameters.getSize())]
    parameter_errors = [fit_parameters[i].getError() for i in range(fit_parameters.getSize())]

    # Print the fit results
    print("Fit Results:")
    for i in range(len(parameter_names)):
        print("{0} = {1:.3f} +/- {2:.3f}".format(parameter_names[i], parameter_values[i], parameter_errors[i]))

    # Create a legend
    legend = plt.legend()

    # Save the plot to a file
    plt.savefig(output_filename)

    # Show the plot
    plt.show()

