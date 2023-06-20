# primenumbercalculator
This is a place to show my prime number calculating algorithms.

-----BENSORIGINAL.CPP-----
This prime number calculator relies on two theories of math:
1. All non-prime numbers are divisible by one or more prime numbers.
2. The square root of a number is the middle point for sets of factors.

What do I mean by this? Assume we wanted to find all sets of factors of 36. We know that they are:
(2 x 18), (3 x 12), (4 x 9), (6 x 6), (9 x 4), (3 x 12), (18 x 2).
Notice how after 36's square root, 6, there are no new numbers in our collection of sets. This means that we only need to calculate the first half of factors, which we can find by taking the square root of a number.

This calculator is able to find primes up until 10 million in just .925 seconds and all primes up until 1 billion in just ~741 seconds (which is about 7 mins and 51 seconds).

I will continue to optimize this, but as for now I'm satisfied with it's speed and unsure how to continue.

---------------------------
