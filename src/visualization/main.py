import matplotlib.pyplot as plt
import numpy as np

class Visualization:
    def __init__(self):
        pass

    def open_file(self):
        with open("output.txt", "r") as fh:
            return fh.read()
    
    def parse_data(self, data):
        lines = data.split('\n')
        labels = []
        default_times = []
        omp_times = []
        
        i = 0
        while i < len(lines):
            if lines[i].strip() and i + 2 < len(lines):
                label = lines[i].strip()
                default_line = lines[i + 1].strip()
                omp_line = lines[i + 2].strip()
                
                try:
                    default_time = float(default_line.split('in')[1].split('sd')[0].strip())
                    omp_time = float(omp_line.split('in')[1].split('sd')[0].strip())
                except (IndexError, ValueError) as e:
                    print(f"Error parsing lines: {lines[i]}, {lines[i+1]}, {lines[i+2]}")
                    print(e)
                    i += 3
                    continue
                
                labels.append(label)
                default_times.append(default_time)
                omp_times.append(omp_time)
                
                i += 3
            else:
                i += 1
        
        print("Parsed labels:", labels)
        print("Parsed default times:", default_times)
        print("Parsed OMP times:", omp_times)
        
        return labels, default_times, omp_times

    def visualize(self):
        data = self.open_file()
        labels, default_times, omp_times = self.parse_data(data)
        
        x = np.arange(len(labels))
        width = 0.35

        fig, ax = plt.subplots()
        ax.bar(x - width/2, default_times, width, label='Default')
        ax.bar(x + width/2, omp_times, width, label='With OMP')

        ax.set_xlabel('Benchmark')
        ax.set_ylabel('Time (sd)')
        ax.set_title('Benchmarking Results')
        ax.set_xticks(x)
        ax.set_xticklabels(labels)
        ax.legend()

        plt.show()

# Example usage
vis = Visualization()
vis.visualize()