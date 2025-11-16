import pandas as pd
import matplotlib.pyplot as plt
import os

plt.rcParams['font.family'] = 'DejaVu Sans'


def plot_quick_sort_results():
    fig, axes = plt.subplots(1, 3, figsize=(18, 5))
    fig.suptitle('Standard Quick Sort', fontsize=16, fontweight='bold')
    df_random = pd.read_csv('src/quick_sort_random.csv')
    axes[0].plot(df_random['Size'], df_random['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4, color='blue')
    axes[0].set_xlabel('Array Size', fontsize=12)
    axes[0].set_ylabel('Time (microseconds)', fontsize=12)
    axes[0].set_title('Random Data', fontsize=13, fontweight='bold')
    axes[0].grid(True, alpha=0.3)
    df_reversed = pd.read_csv('src/quick_sort_reversed.csv')
    axes[1].plot(df_reversed['Size'], df_reversed['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4, color='red')
    axes[1].set_xlabel('Array Size', fontsize=12)
    axes[1].set_ylabel('Time (microseconds)', fontsize=12)
    axes[1].set_title('Reversed Data', fontsize=13, fontweight='bold')
    axes[1].grid(True, alpha=0.3)
    df_nearly = pd.read_csv('src/quick_sort_nearly_sorted.csv')
    axes[2].plot(df_nearly['Size'], df_nearly['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4, color='green')
    axes[2].set_xlabel('Array Size', fontsize=12)
    axes[2].set_ylabel('Time (microseconds)', fontsize=12)
    axes[2].set_title('Nearly Sorted Data', fontsize=13, fontweight='bold')
    axes[2].grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig('plots/quick_sort_results.png', dpi=300, bbox_inches='tight')
    print("Graph saved: quick_sort_results.png")
    plt.close()


def plot_intro_sort_results():
    fig, axes = plt.subplots(1, 3, figsize=(18, 5))
    fig.suptitle('Intro Sort', fontsize=16, fontweight='bold')
    df_random = pd.read_csv('src/intro_sort_random.csv')
    axes[0].plot(df_random['Size'], df_random['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4, color='blue')
    axes[0].set_xlabel('Array Size', fontsize=12)
    axes[0].set_ylabel('Time (microseconds)', fontsize=12)
    axes[0].set_title('Random Data', fontsize=13, fontweight='bold')
    axes[0].grid(True, alpha=0.3)
    df_reversed = pd.read_csv('src/intro_sort_reversed.csv')
    axes[1].plot(df_reversed['Size'], df_reversed['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4, color='red')
    axes[1].set_xlabel('Array Size', fontsize=12)
    axes[1].set_ylabel('Time (microseconds)', fontsize=12)
    axes[1].set_title('Reversed Data', fontsize=13, fontweight='bold')
    axes[1].grid(True, alpha=0.3)
    df_nearly = pd.read_csv('src/intro_sort_nearly_sorted.csv')
    axes[2].plot(df_nearly['Size'], df_nearly['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4, color='green')
    axes[2].set_xlabel('Array Size', fontsize=12)
    axes[2].set_ylabel('Time (microseconds)', fontsize=12)
    axes[2].set_title('Nearly Sorted Data', fontsize=13, fontweight='bold')
    axes[2].grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig('plots/intro_sort_results.png', dpi=300, bbox_inches='tight')
    print("Graph saved: intro_sort_results.png")
    plt.close()


def plot_comparison():
    fig, axes = plt.subplots(1, 3, figsize=(18, 5))
    fig.suptitle('Comparison Quick Sort vs Intro Sort)',
                 fontsize=16, fontweight='bold')
    df_quick = pd.read_csv('src/quick_sort_random.csv')
    df_intro = pd.read_csv('src/intro_sort_random.csv')
    axes[0].plot(df_quick['Size'], df_quick['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4,
                 label='Quick Sort', color='blue')
    axes[0].plot(df_intro['Size'], df_intro['Time_microseconds'],
                 marker='s', linewidth=2, markersize=4,
                 label=f'Intro Sort', color='orange')
    axes[0].set_xlabel('Array Size', fontsize=12)
    axes[0].set_ylabel('Time (microseconds)', fontsize=12)
    axes[0].set_title('Random Data', fontsize=13, fontweight='bold')
    axes[0].legend(fontsize=11)
    axes[0].grid(True, alpha=0.3)

    df_quick = pd.read_csv('src/quick_sort_reversed.csv')
    df_intro = pd.read_csv(f'src/intro_sort_reversed.csv')
    axes[1].plot(df_quick['Size'], df_quick['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4,
                 label='Quick Sort', color='blue')
    axes[1].plot(df_intro['Size'], df_intro['Time_microseconds'],
                 marker='s', linewidth=2, markersize=4,
                 label=f'Intro Sort', color='orange')
    axes[1].set_xlabel('Array Size', fontsize=12)
    axes[1].set_ylabel('Time (microseconds)', fontsize=12)
    axes[1].set_title('Reversed Data', fontsize=13, fontweight='bold')
    axes[1].legend(fontsize=11)
    axes[1].grid(True, alpha=0.3)
    df_quick = pd.read_csv('src/quick_sort_nearly_sorted.csv')
    df_intro = pd.read_csv(f'src/intro_sort_nearly_sorted.csv')
    axes[2].plot(df_quick['Size'], df_quick['Time_microseconds'],
                 marker='o', linewidth=2, markersize=4,
                 label='Quick Sort', color='blue')
    axes[2].plot(df_intro['Size'], df_intro['Time_microseconds'],
                 marker='s', linewidth=2, markersize=4,
                 label=f'Intro Sort', color='orange')
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
    print("Building graphs for quick Sort...")
    plot_quick_sort_results()
    print("Building graphs for intro Sort...")
    plot_intro_sort_results()
    print("Building comparison graphs...")
    plot_comparison()
    print("\nAll graphs successfully created!")
    print("\nGenerated files:")
    print("  - quick_sort_results.png")
    print("  - intro_sort_results.png")
    print("  - comparison_results.png")


if __name__ == "__main__":
    main()
