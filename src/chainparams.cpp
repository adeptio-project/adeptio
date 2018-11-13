// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2015-2017 The Adeptio developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>


using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"


/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions

static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
	(0, uint256("0x0000041a18cae812549433c7ccbf1db6a0da33bb91254a451a498219198eeae8"))
	(1000, uint256("0x0000000000011a4f199d639afd11bf0ab20750737f2b3bfe695b63cfa69dcb6b"))
        (10000, uint256("0x0000000000084511d9aafddf73098f56e0cd1043984671aa909a1a12716113df"))
        (100000, uint256("0x000000000018c06c5e0776f504503331c635cf3843f41355ea486ac5bc879c51"))
        (200000, uint256("0x0000000000012840e2d1e2d058971ed6a87434e6b776defee35808b6f94aaa3e"))

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1540349334, // * UNIX timestamp of last checkpoint block
    216357,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x0x00000a5662a9fe0b0fd02e3765b9b8e2e6d033b337d77c4f0d63ed28de96c6e8"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1527677778,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x05ec3f4d9992323d64f4cba4f6ac0079b69277cfc0834a0d6d959fe9ff86b89c"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1527677778,
    0,
    100};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x44;
        pchMessageStart[1] = 0x24;
        pchMessageStart[2] = 0x25;
        pchMessageStart[3] = 0x14;
        vAlertPubKey = ParseHex("0440c946f36751aa0229d5e7f04c3032392e41c794db4b7eb76e0ee132f2b88d872bc9aa142db38fdee812cda69e282d3c537e5a19fcb5f6c6a7fc2192b88ca137");
        nDefaultPort = 9077;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // Adeptio starting difficulty is 1 / 2^12  //20
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Adeptio: 1 day
        nTargetSpacing = 1 * 60;  // Adeptio: 1 minute
        nLastPOWBlock = 345600; // ~240 Days
        nMaturity = 100;
        nMasternodeCountDrift = 20;
	nMasternodeColleteralLimxDev = 10000; //Params().MasternodeColleteralLimxDev()
        nModifierUpdateBlock = 1; // we use the version 2 for dmd
        nMaxMoneyOut = 100000000 * COIN;

        const char* pszTimestamp = "30 May 2018 // With great power comes great responsibility. Adeptio tech.";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("040fbf75ea45bf7eb65f9075e8342b7520d077b66f964e9b1963c96cefd9a2c52e93d0def918e0cd3c91f42821f429b2be4505552dede31c96f95f0d843da0beae") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1527677777;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 4851983;
	
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000041a18cae812549433c7ccbf1db6a0da33bb91254a451a498219198eeae8"));
        assert(genesis.hashMerkleRoot == uint256("0xc122043047ee9acb36875d258b7ebb0d5c08034d0508fac895969e3a282de447"));

	vSeeds.push_back(CDNSSeedData("seed0.adeptio.cc", "seed0.adeptio.cc")); // Primary DNS Seeder;
        vSeeds.push_back(CDNSSeedData("seed1.adeptio.cc", "seed1.adeptio.cc"));
        vSeeds.push_back(CDNSSeedData("seed2.adeptio.cc", "seed2.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed3.adeptio.cc", "seed3.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed4.adeptio.cc", "seed4.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed5.adeptio.cc", "seed5.adeptio.cc"));

        vSeeds.push_back(CDNSSeedData("seed6.adeptio.cc", "seed6.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed7.adeptio.cc", "seed7.adeptio.cc"));
        vSeeds.push_back(CDNSSeedData("seed8.adeptio.cc", "seed8.adeptio.cc"));
        vSeeds.push_back(CDNSSeedData("seed9.adeptio.cc", "seed9.adeptio.cc"));
        vSeeds.push_back(CDNSSeedData("seed10.adeptio.cc", "seed10.adeptio.cc"));
        vSeeds.push_back(CDNSSeedData("seed11.adeptio.cc", "seed11.adeptio.cc"));


        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 23);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 16);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 193);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md 109 	0x8000006d
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x6d).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;


        nPoolMaxTransactions = 3;
        strSporkKey = "049e53e687fdafd78fd42d730fad0e7ea1819396176a2cb85d7a76fa4559cdbd2c2f05330a6f5cbadb44a6c1d324f167e679e9f3e95d9d5649761a3e7f59bf4500";
        strDarksendPoolDummyAddress = "ATRg2hVWT2QT1dxndpPTSM2kvXs8LERWHu";
        nStartMasternodePayments = 1527764160; // After 1 day from init start 
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x14;
        pchMessageStart[1] = 0x44;
        pchMessageStart[2] = 0x25;
        pchMessageStart[3] = 0x54;
        vAlertPubKey = ParseHex("04cd5eaa8c03460c34747d1d1ff3bae7964a9bea28a7a00f180674a807e558958417541b7ba18fd2ddc1d578a3f2caf06bdce196c72a798c03312c6b2a4e707224");
        nDefaultPort = 19077;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Adeptio: 1 day
        nTargetSpacing = 1 * 60;  // Adeptio: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 10;
        nModifierUpdateBlock = 51197; 
        nMaxMoneyOut = 100000000 * COIN;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1527677778;
        genesis.nNonce = 3698642;
	
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000a5662a9fe0b0fd02e3765b9b8e2e6d033b337d77c4f0d63ed28de96c6e8"));

        vFixedSeeds.clear();
        vSeeds.clear();
		
        vSeeds.push_back(CDNSSeedData("testnet.seed0.adeptio.cc", "testnet.seed0.adeptio.cc")); // Primary DNS Seeder;
        vSeeds.push_back(CDNSSeedData("testnet.seed1.adeptio.cc", "testnet.seed1.adeptio.cc"));
        vSeeds.push_back(CDNSSeedData("testnet.seed2.adeptio.cc", "testnet.seed2.adeptio.cc"));
        vSeeds.push_back(CDNSSeedData("testnet.seed3.adeptio.cc", "testnet.seed3.adeptio.cc"));
        vSeeds.push_back(CDNSSeedData("testnet.seed4.adeptio.cc", "testnet.seed4.adeptio.cc"));
        vSeeds.push_back(CDNSSeedData("testnet.seed5.adeptio.cc", "testnet.seed5.adeptio.cc"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 83);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 18);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 193);
        // Testnet alqo BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet alqo BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet alqo BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));


        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;



        nPoolMaxTransactions = 2;
        strSporkKey = "04bbba1f836f32de0c31049a96f6838b46d9119554752eaba90ef7df5370f6a54d9fbc1aa7250cf356f149be2e396b983e9d56a288ceafa1093744b3a4b72c4125";
        strDarksendPoolDummyAddress = "";
        nStartMasternodePayments = 1525177401;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x14;
        pchMessageStart[1] = 0x34;
        pchMessageStart[2] = 0x95;
        pchMessageStart[3] = 0x64;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // Adeptio: 1 day
        nTargetSpacing = 1 * 60;        // Adeptio: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1527677778;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 129918;		
        nDefaultPort = 19077;

	hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x05ec3f4d9992323d64f4cba4f6ac0079b69277cfc0834a0d6d959fe9ff86b89c"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 59000;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
