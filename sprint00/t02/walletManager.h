#pragma once

#include <iostream>

struct Wallet {
    int septims;
};

Wallet* createWallet(const int& septs);
void destroyWallet(Wallet* wallet);
Wallet* createWallets(const int& amount);
void destroyWallets(Wallet* wallets);
