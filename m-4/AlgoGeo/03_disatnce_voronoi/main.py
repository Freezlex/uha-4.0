import numpy as np
import matplotlib.pyplot as plt
from scipy.spatial import Voronoi, voronoi_plot_2d, distance


points = np.random.uniform(0, 100, size=(10, 2))
vor = Voronoi(points)
voronoi_plot_2d(vor)

plt.show()