from collections import defaultdict
import matplotlib.pyplot as plt
import numpy as np

def plot_out_file(filename):
    cmap = plt.get_cmap('jet')

    data = np.loadtxt(filename)

    plt.figure(figsize=(12, 6))

    groups = defaultdict(list)
    for angle, throttle, right, delta in data:
        groups[angle].append((throttle, right))
    num_groups = len(groups)

    for i, (angle, l) in enumerate(groups.items()):
        # if angle > 0: continue
        color = cmap(i / num_groups)
        plt.plot([r[0] for r in l],
                 [r[1] for r in l],
                 color=color,
                 alpha=0.7,
                 linewidth=1,
                 label=f'{angle}' if angle % 10 == 0 else f'_')
    plt.grid(True, linestyle='--', alpha=0.3)
    
    plt.tight_layout()
    plt.legend(loc='best', fontsize='small')
    plt.show()

plot_out_file('../CounterWheelTest.out')
