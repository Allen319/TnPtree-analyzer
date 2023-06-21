import matplotlib.pyplot as plt
import ROOT
import numpy as np

# Open the ROOT file
root_file = ROOT.TFile("2018data.root", "READ")

# Define the legend labels
legends = ["photon50", "photon75", "photon90", "photon120", "photon165", "photon200"]

# Define the binning for the x axis
#x_bins = [50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195, 200, 205, 210, 215, 220, 225, 230, 235, 240, 245]
x_bins = [50 + 5 * x for x in range(40)]

#xticks = np.arange(50, 260, 10)
#xticks_major = xticks[::2]  # Select every other tick

# Set the x-tick labels
#xticklabels = [f'{i}-{i+5}' for i in range(50, 255, 5)]
#xticklabels_major = xticklabels[::2]  # Select every other label

# Set up the matplotlib figure
fig, ax = plt.subplots()

# Loop over the legends
for legend in legends:
    # Create a list to hold the efficiencies and errors
    eff_list = []
    err_up_list = []
    err_down_list = []

    # Loop over the pt bins
    for i, bin_edge in enumerate(x_bins[:-1]):
        # Get the efficiency histogram for the current pt bin and legend
        hist_name = "eff_{0}_pt{1}-{2}".format(legend, bin_edge, x_bins[i+1])
        print(hist_name)
        hist = root_file.Get(hist_name)

        # Get the efficiency and errors
        eff = hist.GetEfficiency(0)
        err_up = hist.GetEfficiencyErrorUp(0)
        err_down = hist.GetEfficiencyErrorLow(0)

        # Append to the lists
        eff_list.append(eff)
        err_up_list.append(err_up)
        err_down_list.append(err_down)

    # Plot the efficiency with errors
    ax.errorbar(x_bins[:-1], eff_list, yerr=[err_down_list, err_up_list], fmt=":", capsize=3, label=legend)

# Set the x and y labels
ax.set_xlabel("pt bin")
ax.set_ylabel("Efficiency")
ax.set_xticks(x_bins[::4])
ax.set_xticklabels(x_bins[::4])

#ax.set_xticks(xticks_major)
#ax.set_xticklabels(xticklabels_major)
# Set the legend
ax.legend()
plt.savefig('2018data.pdf', format='pdf')
# Show the plot
plt.show()

