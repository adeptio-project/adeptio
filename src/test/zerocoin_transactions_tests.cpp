// Copyright (c) 2017-2018 The ADE developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Denominations.h"
#include "amount.h"
#include "chainparams.h"
#include "coincontrol.h"
#include "main.h"
#include "wallet/wallet.h"
#include "wallet/walletdb.h"
#include "txdb.h"
#include <boost/test/unit_test.hpp>
#include <iostream>

using namespace libzerocoin;


BOOST_AUTO_TEST_SUITE(zerocoin_transactions_tests)

static CWallet cWallet("unlocked.dat");

BOOST_AUTO_TEST_CASE(zerocoin_spend_test)
{
    SelectParams(CBaseChainParams::MAIN);
    ZerocoinParams *ZCParams = Params().Zerocoin_Params(false);
    (void)ZCParams;

    bool fFirstRun;
    cWallet.LoadWallet(fFirstRun);
    cWallet.zadeTracker = unique_ptr<CzADETracker>(new CzADETracker(cWallet.strWalletFile));
    CMutableTransaction tx;
    CWalletTx* wtx = new CWalletTx(&cWallet, tx);
    bool fMintChange=true;
    bool fMinimizeChange=true;
    std::vector<CZerocoinSpend> vSpends;
    std::vector<CZerocoinMint> vMints;
    CAmount nAmount = COIN;

    CZerocoinSpendReceipt receipt;
    cWallet.SpendZerocoin(nAmount, *wtx, receipt, vMints, fMintChange, fMinimizeChange);

    BOOST_CHECK_MESSAGE(receipt.GetStatus() == ZADE_TRX_FUNDS_PROBLEMS, "Failed Invalid Amount Check");

    nAmount = 1;
    CZerocoinSpendReceipt receipt2;
    cWallet.SpendZerocoin(nAmount, *wtx, receipt2, vMints, fMintChange, fMinimizeChange);

    // if using "wallet.dat", instead of "unlocked.dat" need this
    /// BOOST_CHECK_MESSAGE(vString == "Error: Wallet locked, unable to create transaction!"," Locked Wallet Check Failed");

    BOOST_CHECK_MESSAGE(receipt2.GetStatus() == ZADE_TRX_FUNDS_PROBLEMS, "Failed Invalid Amount Check");

}

BOOST_AUTO_TEST_SUITE_END()
