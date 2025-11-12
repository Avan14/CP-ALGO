import random
import numpy as np

# Set seed for reproducibility
random.seed(42)
np.random.seed(42)

def get_probability(event_samples):
    """Calculate probability from samples"""
    return sum(event_samples) / len(event_samples)


n_samples = 10
burglary_samples = [random.randint(0, 1) for _ in range(n_samples)]
earthquake_samples = [random.randint(0, 1) for _ in range(n_samples)]

P_B = get_probability(burglary_samples)
P_E = get_probability(earthquake_samples)

print(f"P(B) = {P_B}")
print(f"P(E) = {P_E}")

alarm_samples = [max(b, e) for b, e in zip(burglary_samples, earthquake_samples)]
P_A = get_probability(alarm_samples)

print(f"P(A) = {P_A}")

john_call_samples = [random.randint(0, 1) for _ in range(n_samples)]
mary_call_samples = [random.randint(0, 1) for _ in range(n_samples)]

count = sum(1 for i in range(n_samples) 
            if burglary_samples[i] == 1 and 
            earthquake_samples[i] == 0 and 
            alarm_samples[i] == 0 and
            john_call_samples[i] == 1 and 
            mary_call_samples[i] == 1)

P_result = count / n_samples

print(f"\nP(B=1, E=0, A=0, JC=1, MC=1) = {P_result}")
