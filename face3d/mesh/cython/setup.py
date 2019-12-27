"""python setup.py build_ext -i to compile"""
from distutils.core import setup
from distutils.core import Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext
import numpy as np

setup(name='mesh_core_cython',
      cmdclass={'build_ext': build_ext},
      ext_modules=[
          Extension('mesh_core_cython',
                    sources=['mesh_core_cython.pyx', 'mesh_core.cpp'],
                    language='c++',
                    include_dirs=[np.get_include()])
      ])
