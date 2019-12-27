"""Simple example of pipeline 3D obj (process) --> 2d image"""
import os
import sys
from time import time

import numpy as np
import scipy.io as sio
from skimage import io
import matplotlib.pyplot as plt

sys.path.append('..')
import face3d
from face3d import mesh

# 1. Load mesh data
# mesh data consists of: vertices, triangles, color(optional), texture(optional)
# here use colors to represent the texture of face surface
C = sio.loadmat('Data/example1.mat')
vertices = C['vertices']
colors = C['colors']
triangles = C['triangles']
colors = colors / np.max(colors)

# 2. Modify vertices (transformation. change position of obj)
# change the position of mesh object in world space
# space. target size=180 for example
s = 180 / (np.max(vertices[:, 1]) - np.min(vertices[:, 1]))
# Rotate 30 degree
R = mesh.transform.angle2matrix([0, 30, 0])
# No translation. center of object: [0, 0, 0]
t = [0, 0, 0]
transformed_vertices = mesh.transform.similarity_transform(vertices, s, R, t)
