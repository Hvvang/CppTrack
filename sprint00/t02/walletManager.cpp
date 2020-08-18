#include "walletManager.h"

Wallet* createWallet(const int& septs) {
  Wallet* wallet = new Wallet;

  wallet->septims = septs;
  return wallet;
}

void destroyWallet(Wallet* wallet) {
  delete wallet;
}

Wallet* createWallets(const int& amount) {
  Wallet* wallets = new Wallet[amount];

  return wallets;
}

void destroyWallets(Wallet* wallets) {
  delete [] wallets;
}
