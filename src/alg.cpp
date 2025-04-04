// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value <= 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
  for (uint64_t i = 5; i * i <= value; i = i + 6) {
    if (value % i == 0 || value % (i + 2) == 0)
      return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t result = 2;
  if (n == 1) {
    result = 2;
  } else if (n == 2) {
    result = 3;
  } else {
    uint64_t count = 2;
    uint64_t num = 5;
    while (count < n) {
      if (checkPrime(num)) {
        count++;
      }
      if (count == n) {
        result = num;
        break;
      }
      num += 2;
      if (checkPrime(num)) {
        count++;
      }
      if (count == n) {
        result = num;
        break;
      }
      num += 4;
    }
  }
  return result;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t num = value + 1;
  while (true) {
    if (checkPrime(num)) {
      return num;
    }
    num++;
  }
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return 2; 
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound - 2; ++i) {
    if (checkPrime(i) && checkPrime(i + 2) && i + 2 < hbound) {
      count++;
    }
  }
  return 1;  
}
