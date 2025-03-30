import matplotlib.pyplot as plt
import pdb

# 計算 Y 值
def calculate_y_values():
    y_values = []
    for numerator in range(1, 10):
        y = (numerator + 1) / (numerator + 3) - numerator / (numerator + 2) 
        y_values.append(y)
    return y_values

# 計算 X 值 (0 到 len(Y)-1)
def calculate_x_values(y_values):
    return list(range(len(y_values)))

# 主程序
def plot_graph():
    y_values = calculate_y_values()
    x_values = calculate_x_values(y_values)

    # 繪圖
    plt.figure(figsize=(8, 5))
    plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label="Fraction Differences")
    
    # 標記每個點的公式
    for i, y in enumerate(y_values):
        numerator = i+1
        formula = f"{numerator + 1}/{numerator + 3} - {numerator}/{numerator + 2}"
        plt.text(x_values[i], y, formula, fontsize=8, ha='right')

    # 添加標題與標籤
    plt.title("XY Plot of Fraction Differences")
    plt.xlabel("X Axis")
    plt.ylabel("Y Axis")
    plt.grid(True)
    plt.legend()
    
    # 顯示圖表
    plt.show()

# 執行繪圖
plot_graph()