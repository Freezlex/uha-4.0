import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler
from numpy.random import uniform
from sklearn.datasets import make_blobs
import seaborn as sbn
import random


def distance(point, data):
    return np.sqrt(np.sum((point - data) ** 2, axis=1))


class KMeans:
    def __init__(self, n_clusters=8, it_max=300):
        self.n_clusters = n_clusters
        self.it_max = it_max
        self.centroids = None

    def calc(self, dataset):
        # On séléctione un point aléatoire dénotre dataset pour notre premier centre
        self.centroids = random.choices(dataset)
        for _ in range(self.n_clusters - 1):
            # On calcul la distance à partir de notre point au centroids
            dists = np.sum([distance(centroid, dataset) for centroid in self.centroids], axis=0)
            # On normalise les distances
            dists /= np.sum(dists)
            # On récupère les points restants en fonction de leur distance
            new_centroid_idx, = np.random.choice(range(len(dataset)), size=1, p=dists)
            self.centroids += [dataset[new_centroid_idx]]
        # Iterate, adjusting centroids until converged or until passed max_iter
        # On ajuste les centroïdes générés jusqu'à convergence ou alors jusqu'à ce que l'on dépasse le it_max
        iteration = 0
        prev_centroids = None
        while np.not_equal(self.centroids, prev_centroids).any() and iteration < self.it_max:
            # Sort each datapoint, assigning to nearest centroid
            points = [[] for _ in range(self.n_clusters)]
            for x in dataset:
                dists = distance(x, self.centroids)
                centroid_idx = np.argmin(dists)
                points[centroid_idx].append(x)
            # Push current centroids to previous, reassign centroids as mean of the points belonging to them
            prev_centroids = self.centroids
            self.centroids = [np.mean(cluster, axis=0) for cluster in points]
            for i, centroid in enumerate(self.centroids):
                if np.isnan(centroid).any():  # Catch any np.nans, resulting from a centroid having no points
                    self.centroids[i] = prev_centroids[i]
            iteration += 1

    def evaluate(self, sources):
        centroids = []
        centroid_idxs = []
        for x in sources:
            dists = distance(x, self.centroids)
            centroid_idx = np.argmin(dists)
            centroids.append(self.centroids[centroid_idx])
            centroid_idxs.append(centroid_idx)
        return centroids, centroid_idxs


# Create a dataset of 2D distributions
centers = 5
X_train, true_labels = make_blobs(n_samples=100, centers=centers, random_state=42)
X_train = StandardScaler().fit_transform(X_train)
# Fit centroids to dataset
x = KMeans(n_clusters=centers)
x.calc(X_train)
# View results
class_centers, classification = x.evaluate(X_train)
# On utilise une librairie pour afficher les points et les clusters générés
sbn.scatterplot(x=[X[0] for X in X_train], y=[X[1] for X in X_train], hue=true_labels, style=classification,
                palette="deep", legend=None)

plt.plot([x for x, _ in x.centroids], [y for _, y in x.centroids], 'k+', markersize=10)
plt.show()
