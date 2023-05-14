import numpy as np


def f(x): return x**2 - 2
def f_prime(x): return 2*x


newton_raphson = 1.4 - (f(1.4))/(f_prime(1.4))

print("newton_raphson =", newton_raphson)
print("sqrt(2) =", np.sqrt(2))


def my_newton(f, df, x0, tol):
    # output is an estimation of the root of f
    # using the Newton Raphson method
    # recursive implementation
    if abs(f(x0)) < tol:
        return x0
    else:
        return my_newton(f, df, x0 - f(x0)/df(x0), tol)

    estimate = my_newton(f, f_prime, 1.5, 1e-6)


print("estimate =", estimate)
print("sqrt(2) =", np.sqrt(2))

x0 = 0.29
x1 = x0-(x0**3+3*x0**2-2*x0-5)/(3*x0**2+6*x0-2)
print("x1 =", x1)
