import numpy as np
import matplotlib.pyplot as plt
plt.style.use('seaborn-poster')
%matplotlib inline

x = np.arange(0, 2*np.pi, 0.01)
# compute function
omega = 100
epsilon = 0.01

y = np.cos(x)
y_noise = y + epsilon*np.sin(omega*x)

# Plot solution
plt.figure(figsize=(12, 8))
plt.plot(x, y_noise, 'r-',
         label='cos(x) + noise')
plt.plot(x, y, 'b-',
         label='cos(x)')

plt.xlabel('x')
plt.ylabel('y')

plt.legend()
plt.show()

x = np.arange(0, 2*np.pi, 0.01)
# compute function
y = -np.sin(x)
y_noise = y + epsilon*omega*np.cos(omega*x)

# Plot solution
plt.figure(figsize=(12, 8))
plt.plot(x, y_noise, 'r-',
         label='Derivative cos(x) + noise')
plt.plot(x, y, 'b-',
         label='Derivative of cos(x)')

plt.xlabel('x')
plt.ylabel('y')

plt.legend()
plt.show()


# define step size
h = 1
# define number of iterations to perform
iterations = 20
# list to store our step sizes
step_size = []
# list to store max error for each step size
max_error = []

for i in range(iterations):
    # halve the step size
    h /= 2
    # store this step size
    step_size.append(h)
    # compute new grid
    x = np.arange(0, 2 * np.pi, h)
    # compute function value at grid
    y = np.cos(x)
    # compute vector of forward differences
    forward_diff = np.diff(y)/h
    # compute corresponding grid
    x_diff = x[:-1]
    # compute exact solution
    exact_solution = -np.sin(x_diff)

    # Compute max error between
    # numerical derivative and exact solution
    max_error.append(
        max(abs(exact_solution - forward_diff)))

# produce log-log plot of max error versus step size
plt.figure(figsize=(12, 8))
plt.loglog(step_size, max_error, 'v')
plt.show()
