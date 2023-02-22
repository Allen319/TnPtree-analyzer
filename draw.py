import matplotlib.pyplot as plt
import numpy as np

# Define the x values and bin edges
bin_edges = [0, 2, 4, 6, 8, 10]
x_values = np.array([1, 3, 5, 7, 9])

# Define the y values and error bars for each graph
y_values_1 = np.array([3, 5, 2, 7, 4])
y_errors_1 = np.array([0.5, 0.8, 0.3, 1.2, 0.6])

y_values_2 = np.array([2, 6, 4, 9, 5])
y_errors_2 = np.array([0.3, 0.6, 0.4, 1.1, 0.5])

# Bin the x values
bin_indices = np.digitize(x_values, bin_edges)
binned_x_values = [x_values[bin_indices == i] for i in range(1, len(bin_edges))]

# Create a figure with a single subplot
fig, ax = plt.subplots()

# Plot the first graph with error bars
ax.errorbar(x_values, y_values_1, yerr=y_errors_1, fmt='o', capsize=5, label='Graph 1')

# Plot the second graph with error bars
ax.errorbar(x_values, y_values_2, yerr=y_errors_2, fmt='o', capsize=5, label='Graph 2')

# Set the x-ticks to the bin edges
ax.set_xticks(bin_edges)

# Add a legend with y-values
handles, labels = ax.get_legend_handles_labels()
ax.legend(handles, [f'{l}: {v}' for l, v in zip(labels, [y_values_1, y_values_2])], loc='best')

# Set the axis labels and title
ax.set_xlabel('X Values')
ax.set_ylabel('Y Values')
ax.set_title('Multiple Graphs with Error Bars')

# Save the plot as a PDF file
plt.savefig('multiple_graphs_with_error_bars.pdf', format='pdf')

# Display the plot
plt.show()

