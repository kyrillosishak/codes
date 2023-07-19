import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt


def create_graph_from_csv(file_pathh):
    df = pd.read_csv(file_pathh)
    graphh = nx.Graph()

    for _, row in df.iterrows():
        source = str(row['A'])
        target = str(row['B'])
        graphh.add_edge(source, target)

    return graphh


def find_loops(graphh):
    loops = nx.simple_cycles(graphh)

    if loops:
        print("Loops found:")
        for loop in loops:
            print(loop)
    else:
        print("No loops found in the graph.")


def visualize_graph(graphh):
    plt.figure(figsize=(8, 6))
    pos = nx.spring_layout(graphh)
    nx.draw(graphh, pos, with_labels=True, node_color='lightblue', node_size=500, font_size=10)
    plt.title("Graph Visualization")
    plt.show()


file_path = 'test.csv'

graph = create_graph_from_csv(file_path)
find_loops(graph)
visualize_graph(graph)
