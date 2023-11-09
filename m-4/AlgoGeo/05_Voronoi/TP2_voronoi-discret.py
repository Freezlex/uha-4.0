import math
import sys
from math import sqrt
import numpy as np
import random
import cv2
import matplotlib.pyplot as plt


class Mask:
    def __init__(self, x, y, d):
        self.x = x
        self.y = y
        self.d = d


class Pixel:
    def __init__(self, c, d):
        self.c = c
        self.d = d

    def color_to_rgb(self):
        return tuple(int(self.c.lstrip('#')[i:i + 2], 16) for i in (0, 2, 4))


class Point:
    def __init__(self, x, y, c):
        self.x = x
        self.y = y
        self.c = c


class Image:

    def __init__(self, path):
        self.source = cv2.imread(path, cv2.IMREAD_UNCHANGED)
        self.distance = [[sys.maxsize] * self.source.shape[1] for i in range(self.source.shape[0])]
        self.generate_random()

    def generate_random(self):
        for i in range(round((self.source.shape[0] * self.source.shape[1]) * 0.001)):
            (x, y, c) = [
                round(random.randint(0, self.source.shape[1] - 1)),
                round(random.randint(0, self.source.shape[0] - 1)),
                tuple(np.random.choice(range(255), size=3))]
            self.source[y][x] = c
            self.distance[y][x] = 0

    def write_and_display_image(self):
        cv2.imshow('generated-image', self.source)
        cv2.waitKey(0)
        cv2.destroyWindow('generated-image')


mask_top_to_bottom = [
    Mask(-1, 0, 1),
    Mask(-1, -1, sqrt(2)),
    Mask(0, -1, 1),
    Mask(1, -1, sqrt(2))
]

mask_bottom_to_top = [
    Mask(1, 0, 1),
    Mask(1, 1, sqrt(2)),
    Mask(0, 1, 1),
    Mask(-1, 1, sqrt(2))
]


def voronoi(i):
    for y, col in enumerate(i.source):
        for x, row in enumerate(i.source[y]):
            current = i.distance[y][x]

            op_mask = None
            for mask in mask_top_to_bottom:
                if 0 <= y + mask.y < len(i.source) and 0 <= x + mask.x < len(i.source[y + mask.y]):
                    if op_mask is None or i.distance[y + mask.y][x + mask.x] < i.distance[y + op_mask.y][x + op_mask.x]:
                        op_mask = mask

            if op_mask is not None and current > (i.distance[y + op_mask.y][x + op_mask.x] + op_mask.d):
                i.source[y][x] = i.source[y + op_mask.y][x + op_mask.x]
                i.distance[y][x] = i.distance[y + op_mask.y][x + op_mask.x] + op_mask.d

    for y, col in reversed(list(enumerate(i.source))):
        for x, row in reversed(list(enumerate(i.source[y]))):
            current = i.distance[y][x]

            op_mask = None
            for mask in mask_bottom_to_top:
                if 0 <= y + mask.y < len(i.source) and 0 <= x + mask.x < len(i.source[y + mask.y]):
                    if op_mask is None or i.distance[y + mask.y][x + mask.x] < i.distance[y + op_mask.y][x + op_mask.x]:
                        op_mask = mask

            if op_mask is not None and current > (i.distance[y + op_mask.y][x + op_mask.x] + op_mask.d):
                i.source[y][x] = i.source[y + op_mask.y][x + op_mask.x]
                i.distance[y][x] = i.distance[y + op_mask.y][x + op_mask.x] + op_mask.d


image = Image("./sample.jpg")
voronoi(image)
image.write_and_display_image()
