from collections import defaultdict
import matplotlib.pyplot as plt
import numpy as np

def plot_out_file(filename):
    cmap = plt.get_cmap('jet')

    data = np.loadtxt(filename, skiprows=1)
    
    with open(filename, 'r') as f:
        line1 = f.readline().split()
        from_min, from_max = map(float, line1)

    plt.figure(figsize=(12, 6))

    groups = defaultdict(list)
    for to_min, to_max, target in data:
        groups[(to_min, to_max)].append(target)
    num_groups = len(groups)

    for i, ((t_min, t_max), y_values) in enumerate(groups.items()):
        color = cmap(i / num_groups)
        plt.plot(np.linspace(from_min, from_max, len(y_values)),
                 y_values,
                 color=color,
                 alpha=0.7,
                 linewidth=1)
    plt.xlabel('From Min to From Max')
    plt.ylabel('Target Value')
    plt.grid(True, linestyle='--', alpha=0.3)
    
    plt.tight_layout()
    plt.show()

plot_out_file('../AmplifyTest.out')
