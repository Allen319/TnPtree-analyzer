import matplotlib.pyplot as plt
import ROOT
import numpy as np

# Open the ROOT file
root_file = ROOT.TFile("2017datafull.root", "READ")

# Define the legend labels
legends = ["photon50", "photon75", "photon90", "photon120", "photon165", "photon200"]
cutoff = [90, 120,135,180, 210, 400]

# Define the binning for the x axis
#x_bins = [50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195, 200, 205, 210, 215, 220, 225, 230, 235, 240, 245]
x_bins = [50 + 5 * x for x in range(72)]

#xticks = np.arange(50, 260, 10)
#xticks_major = xticks[::2]  # Select every other tick

# Set the x-tick labels
xticklabels = [f'{i}' for i in range(50, 425, 25)]
xticklabels_major = xticklabels[::5]  # Select every other label

# Set up the matplotlib figure
fig, ax = plt.subplots()

# Loop over the legends
for trig, legend in enumerate(legends):
    # Create a list to hold the efficiencies and errors
    eff_list = []
    err_up_list = []
    err_down_list = []

    # Loop over the pt bins
    for i, bin_edge in enumerate(x_bins[:-1]):
        print(bin_edge)
        # Get the efficiency histogram for the current pt bin and legend
        hist_name = "eff_{0}_pt{1}-{2}".format(legend, bin_edge, x_bins[i+1])
        print(hist_name)
        hist = root_file.Get("test/" + hist_name)

        # Get the efficiency and errors
        print(type(hist).__name__)
        if type(hist).__name__ == "TObject":
            eff = 0.
            err_up = 0.
            err_down = 0.
        else:
            eff = hist.GetEfficiency(0)
            err_up = hist.GetEfficiencyErrorUp(0)
            err_down = hist.GetEfficiencyErrorLow(0)

        # Append to the lists
        if bin_edge >= cutoff[trig]:
            eff_list.append(0.)
            err_up_list.append(0.)
            err_down_list.append(0.)
        else:
            eff_list.append(eff)
            err_up_list.append(err_up)
            err_down_list.append(err_down)

    # Find the index corresponding to the cutoff value
    cutoff_index = x_bins.index(cutoff[trig])
    # Plot the efficiency with errors
    ax.errorbar(x_bins[:cutoff_index], eff_list[:cutoff_index], yerr=[err_down_list[:cutoff_index], err_up_list[:cutoff_index]], fmt=":", capsize=3, label=legend)


    # Plot the efficiency with errors
    print(len(x_bins[:cutoff_index]), print(len(eff_list[:cutoff_index])))
    #ax.plot(x_bins[:cutoff_index], eff_list[:cutoff_index], ':', label=legend)
    print(len(x_bins[cutoff_index:]), print(len(eff_list[cutoff_index:])))
 
    #ax.plot(x_bins[cutoff_index:-1], eff_list[cutoff_index:], '-', label='_nolegend_')

# Set the x and y labels
ax.set_xlabel("pt bin")
ax.set_ylabel("Efficiency")
#ax.set_xticks(x_bins[::4])
#ax.set_xticklabels(x_bins[::4])
ax.set_xticks(range(50, 425, 25))
ax.set_xticklabels(xticklabels)

#ax.set_xticks(xticks_major)
#ax.set_xticklabels(xticklabels_major)
# Set the legend
ax.legend()
plt.savefig('2017data.pdf', format='pdf')
# Show the plot
plt.show()

