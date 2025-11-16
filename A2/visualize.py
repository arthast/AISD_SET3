import pandas as pd
import matplotlib.pyplot as plt
import os

plt.rcParams['font.family'] = 'DejaVu Sans'


def plot_merge_sort_results():
    fig, axes = plt.subplots(1, 3, figsize=(18, 5))
    fig.suptitle('Standard Merge Sort', fontsize=16, fontweight='bold')
    df_random = pd.read_csv('src/merge_sort_random.csv')
    axes[0].plot(df_random['Size'], df_random['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4, color='blue')
    axes[0].set_xlabel('Array Size', fontsize=12)
    axes[0].set_ylabel('Time (microseconds)', fontsize=12)
    axes[0].set_title('Random Data', fontsize=13, fontweight='bold')
    axes[0].grid(True, alpha=0.3)
    df_reversed = pd.read_csv('src/merge_sort_reversed.csv')
    axes[1].plot(df_reversed['Size'], df_reversed['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4, color='red')
    axes[1].set_xlabel('Array Size', fontsize=12)
    axes[1].set_ylabel('Time (microseconds)', fontsize=12)
    axes[1].set_title('Reversed Data', fontsize=13, fontweight='bold')
    axes[1].grid(True, alpha=0.3)
    df_nearly = pd.read_csv('src/merge_sort_nearly_sorted.csv')
    axes[2].plot(df_nearly['Size'], df_nearly['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4, color='green')
    axes[2].set_xlabel('Array Size', fontsize=12)
    axes[2].set_ylabel('Time (microseconds)', fontsize=12)
    axes[2].set_title('Nearly Sorted Data', fontsize=13, fontweight='bold')
    axes[2].grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig('plots/merge_sort_results.png', dpi=300, bbox_inches='tight')
    print("Graph saved: merge_sort_results.png")
    plt.close()


def plot_hybrid_sort_results():
    thresholds = [5, 10, 20, 30, 50, 300, 500, 1000]
    colors = ['#1f77b4', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd', '#8c564b', '#e377c2', '#7f7f7f']
    fig, axes = plt.subplots(1, 3, figsize=(18, 5))
    fig.suptitle('Hybrid Merge+Insertion Sort',
                 fontsize=16, fontweight='bold')
    axes[0].set_xlabel('Array Size', fontsize=12)
    axes[0].set_ylabel('Time (microseconds)', fontsize=12)
    axes[0].set_title('Random Data', fontsize=13, fontweight='bold')
    axes[0].grid(True, alpha=0.3)
    for i, threshold in enumerate(thresholds):
        filename = f'src/hybrid_sort_random_t{threshold}.csv'
        if os.path.exists(filename):
            df = pd.read_csv(filename)
            axes[0].plot(df['Size'], df['Time_microseconds'],
                         marker='o', linewidth=2, markersize=3,
                         label=f'threshold={threshold}', color=colors[i])
    axes[0].legend(fontsize=10)
    axes[1].set_xlabel('Array Size', fontsize=12)
    axes[1].set_ylabel('Time (microseconds)', fontsize=12)
    axes[1].set_title('Reversed Data', fontsize=13, fontweight='bold')
    axes[1].grid(True, alpha=0.3)
    for i, threshold in enumerate(thresholds):
        filename = f'src/hybrid_sort_reversed_t{threshold}.csv'
        if os.path.exists(filename):
            df = pd.read_csv(filename)
            axes[1].plot(df['Size'], df['Time_microseconds'],
                         marker='o', linewidth=2, markersize=3,
                         label=f'threshold={threshold}', color=colors[i])
    axes[1].legend(fontsize=10)
    axes[2].set_xlabel('Array Size', fontsize=12)
    axes[2].set_ylabel('Time (microseconds)', fontsize=12)
    axes[2].set_title('Nearly Sorted Data', fontsize=13, fontweight='bold')
    axes[2].grid(True, alpha=0.3)
    for i, threshold in enumerate(thresholds):
        filename = f'src/hybrid_sort_nearly_sorted_t{threshold}.csv'
        if os.path.exists(filename):
            df = pd.read_csv(filename)
            axes[2].plot(df['Size'], df['Time_microseconds'],
                         marker='o', linewidth=2, markersize=3,
                         label=f'threshold={threshold}', color=colors[i])
    axes[2].legend(fontsize=10)
    plt.tight_layout()
    plt.savefig('plots/hybrid_sort_results.png', dpi=300, bbox_inches='tight')
    print("Graph saved: hybrid_sort_results.png")
    plt.close()


def plot_comparison():
    best_threshold = 20
    worst_threshold = 1000
    fig, axes = plt.subplots(1, 3, figsize=(18, 5))
    fig.suptitle('Comparison Merge Sort vs Hybrid Sort)',
                 fontsize=16, fontweight='bold')
    df_merge = pd.read_csv('src/merge_sort_random.csv')
    df_hybrid = pd.read_csv(f'src/hybrid_sort_random_t{best_threshold}.csv')
    df_worst_hybrid = pd.read_csv(f'src/hybrid_sort_random_t{worst_threshold}.csv')
    axes[0].plot(df_merge['Size'], df_merge['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4,
                 label='Merge Sort', color='blue')
    axes[0].plot(df_hybrid['Size'], df_hybrid['Time_microseconds'],
                 marker='s', linewidth=2, markersize=4,
                 label=f'Hybrid (t={best_threshold})', color='orange')
    axes[0].plot(df_worst_hybrid['Size'], df_worst_hybrid['Time_microseconds'],
                 marker='s', linewidth=2, markersize=4,
                 label=f'Hybrid (t={worst_threshold})', color='gray')
    axes[0].set_xlabel('Array Size', fontsize=12)
    axes[0].set_ylabel('Time (microseconds)', fontsize=12)
    axes[0].set_title('Random Data', fontsize=13, fontweight='bold')
    axes[0].legend(fontsize=11)
    axes[0].grid(True, alpha=0.3)
    df_merge = pd.read_csv('src/merge_sort_reversed.csv')
    df_hybrid = pd.read_csv(f'src/hybrid_sort_reversed_t{best_threshold}.csv')
    df_worst_hybrid = pd.read_csv(f'src/hybrid_sort_reversed_t{worst_threshold}.csv')
    axes[1].plot(df_merge['Size'], df_merge['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4,
                 label='Merge Sort', color='blue')
    axes[1].plot(df_hybrid['Size'], df_hybrid['Time_microseconds'],
                 marker='s', linewidth=2, markersize=4,
                 label=f'Hybrid (t={best_threshold})', color='orange')
    axes[1].plot(df_worst_hybrid['Size'], df_worst_hybrid['Time_microseconds'],
                 marker='s', linewidth=2, markersize=4,
                 label=f'Hybrid (t={worst_threshold})', color='gray')
    axes[1].set_xlabel('Array Size', fontsize=12)
    axes[1].set_ylabel('Time (microseconds)', fontsize=12)
    axes[1].set_title('Reversed Data', fontsize=13, fontweight='bold')
    axes[1].legend(fontsize=11)
    axes[1].grid(True, alpha=0.3)
    df_merge = pd.read_csv('src/merge_sort_nearly_sorted.csv')
    df_hybrid = pd.read_csv(f'src/hybrid_sort_nearly_sorted_t{best_threshold}.csv')
    df_worst_hybrid = pd.read_csv(f'src/hybrid_sort_nearly_sorted_t{worst_threshold}.csv')
    axes[2].plot(df_merge['Size'], df_merge['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4,
                 label='Merge Sort', color='blue')
    axes[2].plot(df_hybrid['Size'], df_hybrid['Time_microseconds'],
                 marker='s', linewidth=2, markersize=4,
                 label=f'Hybrid (t={best_threshold})', color='orange')
    axes[2].plot(df_worst_hybrid['Size'], df_worst_hybrid['Time_microseconds'],
                 marker='s', linewidth=2, markersize=4,
                 label=f'Hybrid (t={worst_threshold})', color='gray')
    axes[2].set_xlabel('Array Size', fontsize=12)
    axes[2].set_ylabel('Time (microseconds)', fontsize=12)
    axes[2].set_title('Nearly Sorted Data', fontsize=13, fontweight='bold')
    axes[2].legend(fontsize=11)
    axes[2].grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig('plots/comparison_results.png', dpi=300, bbox_inches='tight')
    print("Graph saved: comparison_results.png")
    plt.close()


def main():
    print("=== Visualization of Experimental Results ===\n")
    print("Building graphs for Merge Sort...")
    plot_merge_sort_results()
    print("Building graphs for Hybrid Sort...")
    plot_hybrid_sort_results()
    print("Building comparison graphs...")
    plot_comparison()
    print("\nAll graphs successfully created!")
    print("\nGenerated files:")
    print("  - merge_sort_results.png")
    print("  - hybrid_sort_results.png")
    print("  - comparison_results.png")


if __name__ == "__main__":
    main()
