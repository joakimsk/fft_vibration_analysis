## fft_vibration_analysis

Fork from [Klebiano](https://github.com/Klebiano/Accelerometer-FFT---Real-time), have added arduino program for MMA845X, with modified Adafruit library.

Purpose is to clean up things a bit, add some custom code, make some 3D-printable holder for accelerometer and look for vibrations in rotating machinery.

### Discrete Fourier transform
To learn more about DTF, see [Jupyter Notebook gist](https://gist.github.com/jedludlow/3919130) and [FFT Course](https://web.eecs.umich.edu/~fessler/course/451/l/pdf/c5.pdf)

In short, if you want to observe vibrations at 400 Hz, you need to be able to sample at 800 Hz, minimum. In this case, the Nyquist frequency is half the sampling rate, 400 Hz, and the sampling rate is 800 Hz.

When you attach the accelerometer to a vibrating mass, you also change the resonant frequency, so you cannot accurately measure vibrations in small objects.

Since we need a high sampling rate, it may be useful to disable all kinds of on-chip filtering in the accelerometer. It may also be necessary to rewrite serial communication to use pure bytes, and also buffer up before sending data, to reach high sampling rates. See datasheets for details.

We are looking at the Frequency spectrum of the accelerations, as opposed to the Time series of accelerations.

### MMA845X
Max observed samples per second I have received are around 660 Hz, but the MMA845X should be able to do 800 Hz without filtering and reduced resolution. Read the datasheet for more options. We cannot expect to see higher frequencies than 330 Hz due to this. Uses modified Adafruit library, may need to be modified more.

### MPU6050
This is untested by me, look at Klebiano and source origin for more info.

### Test code
Test code for Arduino to test the link between computer and Arduino.

## Mounting of accelerometer to machinery and selection of axis
Currently the accelerometer only outputs Z axis data, to reduce load on serial communication. You may want to look at different axis, or all three together in a future version of the program.

When mounting to machinery, consider using a hard plastic module that can be taped tightly to the machine. In the future, maybe we also could use a few strong magnets? Keep in mind orientation of accelerometer.

### Future thoughts
The Time series is also useful to look at, but currently it is difficult to see that.