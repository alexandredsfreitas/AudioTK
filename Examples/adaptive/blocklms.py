#!/usr/bin/env python

from ATK.Core import DoubleInPointerFilter, DoubleOutPointerFilter
from ATK.Adaptive import DoubleBlockLMSFilter

def filter(input, reference):
  import numpy as np
  output = np.zeros(input.shape, dtype=np.float64)

  infilter = DoubleInPointerFilter(input, False)
  infilter.set_input_sampling_rate(48000)
  reffilter = DoubleInPointerFilter(reference, False)
  reffilter.set_input_sampling_rate(48000)
  rls = DoubleBlockLMSFilter(100)
  rls.set_input_sampling_rate(48000)
  rls.set_memory(0.999)
  rls.set_mu(0.01)
  rls.set_input_port(0, infilter, 0)
  rls.set_input_port(1, reffilter, 0)
  outfilter = DoubleOutPointerFilter(output, False)
  outfilter.set_input_sampling_rate(48000)
  outfilter.set_input_port(0, rls, 0)
  outfilter.process(input.shape[1])

  return output

if __name__ == "__main__":
  import numpy as np
  size = 1200
  
  x = np.arange(size).reshape(1, -1) / 48000.
  d = np.sin(x * 2 * np.pi * 100)
  d.tofile("input_blocklms.dat")
  out = filter(d, d)
  out.tofile("output_blocklms.dat")
  print(d[0,:10])
  print(out[0,:10])

  import matplotlib.pyplot as plt
  plt.plot(x[0], d[0], label="input")
  plt.plot(x[0], out[0], label="output")
  plt.legend()
  plt.show()
