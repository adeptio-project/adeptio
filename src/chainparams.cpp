// Copyright (c) 2010 Satoshi Nakamoto 
// Copyright (c) 2009-2014 The Bitcoin developers 
// Copyright (c) 2014-2015 The Dash developers 
// Copyright (c) 2015-2017 The ADEX developers 
// Copyright (c) 2017-2019 The Adeptio developers 
// Distributed under the MIT software license, see the accompanying 
// file COPYING or http://www.opensource.org/licenses/mit-license.php. 
 
#include "libzerocoin/Params.h" 
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
        (297000, uint256("0x00000000000662025ccae2abe1090f092a633e4d8336008905fe17cee999da02"))
        (300000, uint256("0x000000000000e754529022cbc1991189a333fd6c2580a94bda09128174915b07"))
        (350000, uint256("0x8bd65475ce1a1b91107ec005b80ae73a39dd8a615e487365191eab3f3a724c44"))
        (370000, uint256("0x93c1e14ff1ab4498a48242bb41cdf3627d7bdfd643e9c6e5e175f798520f5328"))
        (380000, uint256("0x873f9a04931424938a315ea0bdbf45900c4ba33eeaa2c8e91a048833f026e3d7"))
        (385000, uint256("0x6498719c37edbac2d7440706ddd57b78944120f39867d57d109476a6e7754519"))
        (389000, uint256("0x6e1b0cf83792d5109a9d0e35bb0d655e3552a7211ea3bfa6b8b721fd9fc4069e"))
        (390000, uint256("0xf271ab9a6f5f90fdc639d9d0a102ec9d2ba1893b05cb50f64b3dd840900d2234"))
        (395000, uint256("0x86d90f24e5463e358f128bec5c756de95b34938556610a07db2c4630a0365723"))
        (395155, uint256("0x916fab063c2c4f3fa53cd3055050c6b6bb244c4f81d6ba06ccdb9951705dde21"))
        (396137, uint256("0xcef24b6ee76c14e6375455be499030fc713dd20686ac0d7ddb7e15af43f2d302"))
        (397000, uint256("0x395d2bcb7e81201db55b411ba2e182a44a8e40a51811e32a0e72a8a6cddea291"))
        (397700, uint256("0x1622e3df94c390f101534d4f6ee64f793efea8e79a2c7955e4e4bd71ae346956"))
        (397379, uint256("0x4c3e152db5ec70856456a1eacf7fecc614b7b9be92215582ada48e599bb3c09a"))
        (397724, uint256("0x8ebf117bf078e3af424521c8a6c600f22e5afec8868d6f2a75cd91cc41e6f131"))
        (398000, uint256("0xba2dbf9133ed928fcb0d705252d560772511058d2ed14800812a3903fe669eb8"))
        (399000, uint256("0x34387c995763cab3d5f9eaa7b902dd55f89feaf8db4c7cc63ef8d632676c386f"))
        (400000, uint256("0x13733b1776b3a11cf6af1e6f2419d6c3da1d662f814a1fbb5fb0f5e46954ea64"))
        (400500, uint256("0xeb8205f82a1d5405e3399fae444a1d0634e5c4f3982e3ffa5e5fce362d6a575b"))
        (401000, uint256("0x3e283e5777b1de495c965d4e641143feae641a3e76a94fc29724544de0c5d677"))
        (401400, uint256("0xea10f297909026e8d1f468681674bb8c79f9c46bd11d6efa735fa35d1e6dd2e9"))
        (450000, uint256("0xaad6ec975d4eb95b31924b52fe12369ee4978363e52e0bb3b2f1fb0832f63255"))
        (475199, uint256("0xa9d4d607dace292d4be1c9590c1dc250eecc6ffecfa79368dcf05db1501ce741"));

 
 
 
static const Checkpoints::CCheckpointData data = { 
    &mapCheckpoints, 
    1558346988, // * UNIX timestamp of last checkpoint block 
    0,    // * total number of transactions between genesis and last checkpoint 
                //   (the tx=... number in the SetBestChain debug.log lines) 
    2000        // * estimated number of transactions per day after checkpoint 
}; 
 
static Checkpoints::MapCheckpoints mapCheckpointsTestnet = 
    boost::assign::map_list_of 
    (0, uint256("0x001")) 
    (1016800, uint256("0x")); 
static const Checkpoints::CCheckpointData dataTestnet = { 
    &mapCheckpointsTestnet, 
    0, 
    0, 
    250}; 
 
static Checkpoints::MapCheckpoints mapCheckpointsRegtest = 
    boost::assign::map_list_of(0, uint256("0x001")); 
static const Checkpoints::CCheckpointData dataRegtest = { 
    &mapCheckpointsRegtest, 
    0, 
    0, 
    100}; 
 
libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const 
{ 
    assert(this); 
    static CBigNum bnHexModulus = 0; 
    if (!bnHexModulus) 
        bnHexModulus.SetHex(zerocoinModulus); 
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus); 
    static CBigNum bnDecModulus = 0; 
    if (!bnDecModulus) 
        bnDecModulus.SetDec(zerocoinModulus); 
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus); 
 
    if (useModulusV1) 
        return &ZCParamsHex; 
 
    return &ZCParamsDec; 
} 
 
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
        storADEport = 9079; 
        bnProofOfWorkLimit = ~uint256(0) >> 20; // Adeptio starting difficulty is 1 / 2^12  //20 
        nSubsidyHalvingInterval = 210000; 
        nMaxReorganizationDepth = 100; 
        nEnforceBlockUpgradeMajority = 750; // 75% 
        nRejectBlockOutdatedMajority = 950; // 95% 
        nToCheckBlockUpgradeMajority = 1000; // Approximate expected amount of blocks in 7 days (1440*7.5) 
        nMinerThreads = 0; 
        nTargetTimespan = 1 * 60; // Adeptio: 1 day 
        nTargetSpacing = 1 * 60;  // Adeptio: 1 minute 
        nMaturity = 100; 
        nMasternodeCountDrift = 20; 
        nMaxMoneyOut = 100000000 * COIN; 
        strDeveloperFeePayee = "ASpLv9c3UTN6SZXYR29iW46xFGjHRRvPWf";
 
        /** Height or Time Based Activations **/ 
        nLastPOWBlock = 345600;
        nModifierUpdateBlock = 615800; // 19,9M 
        nZerocoinStartHeight = 1000000; // 19,9M 
        nZerocoinStartTime = 1577836800; // 2032y
        nBlockEnforceSerialRange = 19999999; //Enforce serial range starting this block  // 19,9M 
        nBlockRecalculateAccumulators = 19999999; //Trigger a recalculation of accumulators  // 19,9M 
        nBlockFirstFraudulent = 19999999; //First block that bad serials emerged  // 19,9M 
        nBlockLastGoodCheckpoint = 0; //Last valid accumulator checkpoint 
        nBlockEnforceInvalidUTXO = 19999999; //Start enforcing the invalid UTXO's  // 19,9M 
        nInvalidAmountFiltered = 0*COIN; //Amount of invalid coins filtered through exchanges, that should be considered valid 
        nBlockZerocoinV2 = 91000000; //!> The block that zerocoin v2 becomes active. //
        nBlockDoubleAccumulated = 1050010; 
        nEnforceNewSporkKey = 1525158000; //!> Sporks signed after (GMT): Tuesday, May 1, 2018 7:00:00 AM GMT must use the new spork key 
        nRejectOldSporkKey = 1527811200; //!> Fully reject old spork key after (GMT): Friday, June 1, 2018 12:00:00 AM 
 
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

    vFixedSeeds.clear(); 
        vSeeds.clear(); 
 
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
        vSeeds.push_back(CDNSSeedData("seed12.adeptio.cc", "seed12.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed13.adeptio.cc", "seed13.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed14.adeptio.cc", "seed14.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed15.adeptio.cc", "seed15.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed16.adeptio.cc", "seed16.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed17.adeptio.cc", "seed17.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed18.adeptio.cc", "seed18.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed19.adeptio.cc", "seed19.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed20.adeptio.cc", "seed20.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed21.adeptio.cc", "seed21.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed22.adeptio.cc", "seed22.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed23.adeptio.cc", "seed23.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed24.adeptio.cc", "seed24.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed25.adeptio.cc", "seed25.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed26.adeptio.cc", "seed26.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed27.adeptio.cc", "seed27.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed28.adeptio.cc", "seed28.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed29.adeptio.cc", "seed29.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed30.adeptio.cc", "seed30.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed31.adeptio.cc", "seed31.adeptio.cc")); 
        vSeeds.push_back(CDNSSeedData("seed32.adeptio.cc", "seed32.adeptio.cc")); 
 
 
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 23); 
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 16); 
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 193); 
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >(); 
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >(); 
        //     BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md 109     0x8000006d 
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x6d).convert_to_container<std::vector<unsigned char> >(); 
 
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main)); 
 
        fMiningRequiresPeers = true; 
        fAllowMinDifficultyBlocks = false; 
        fDefaultConsistencyChecks = false; 
        fRequireStandard = true; 
        fMineBlocksOnDemand = false; 
        fSkipProofOfWorkCheck = true; 
        fTestnetToBeDeprecatedFieldRPC = false; 
        fHeadersFirstSyncingActive = false; 
 
        nPoolMaxTransactions = 3; 
        nBudgetCycleBlocks = 19999999; //!< Amount of blocks in a months period of time (using 1 minutes per) = (60*24*30) 
        strSporkKey = "049e53e687fdafd78fd42d730fad0e7ea1819396176a2cb85d7a76fa4559cdbd2c2f05330a6f5cbadb44a6c1d324f167e679e9f3e95d9d5649761a3e7f59bf4500"; 
        strSporkKeyOld = "049e53e687fdafd78fd42d730fad0e7ea1819396176a2cb85d7a76fa4559cdbd2c2f05330a6f5cbadb44a6c1d324f167e679e9f3e95d9d5649761a3e7f59bf4500"; 
        strObfuscationPoolDummyAddress = "ATRg2hVWT2QT1dxndpPTSM2kvXs8LERWHu"; 
        nStartMasternodePayments = 1527764160; // After 1 day from init start  
 
        /** Zerocoin */ 
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784" 
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911" 
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363" 
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133" 
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548" 
            "31438167899885040445364023527381951378636564391212010397122822120720357"; 
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each 
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints 
        nMintRequiredConfirmations = 100; //the maximum amount of confirmations until accumulated in 19 
        nRequiredAccumulation = 1; 
        nDefaultSecurityLevel = 100; //full security level for accumulators 
        nZerocoinHeaderVersion = 1; //Block headers must be this version once zerocoin is active 
        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zADE to be stakable 
 
        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee 
        nProposalEstablishmentTime = 60 * 60 * 24; // Proposals must be at least a day old to make it into a budget 
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
        nEnforceBlockUpgradeMajority = 4320; // 75% 
        nRejectBlockOutdatedMajority = 5472; // 95% 
        nToCheckBlockUpgradeMajority = 5760; // 4 days 
        nMinerThreads = 0; 
        nTargetTimespan = 1 * 60; // Adeptio: 1 day 
        nTargetSpacing = 1 * 60;  // Adeptio: 1 minute 
        nLastPOWBlock = 200; 
        nMaturity = 10; 
        nMasternodeCountDrift = 4; 
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 
        nMaxMoneyOut = 100000000 * COIN; 
        nZerocoinStartHeight = 1000000; 
        nZerocoinStartTime = 1577836800; 
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block 
        nBlockRecalculateAccumulators = 9908000; //Trigger a recalculation of accumulators 
        nBlockFirstFraudulent = 9891737; //First block that bad serials emerged 
        nBlockLastGoodCheckpoint = 9891730; //Last valid accumulator checkpoint 
        nBlockEnforceInvalidUTXO = 9902850; //Start enforcing the invalid UTXO's 
        nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid 
        nBlockZerocoinV2 = 1577836800; //!> The block that zerocoin v2 becomes active 
        nEnforceNewSporkKey = 1521604800; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key 
        nRejectOldSporkKey = 1548979200; //!> Reject old spork key after 02/01/2019 @ 12:00am (UTC) 
 
        //! Modify the testnet genesis block so the timestamp is valid for a later start. 
        genesis.nTime = 1558346988; 
        genesis.nBits = 0x1e0ffff0; 
        genesis.nBits = 0x1e0ffff0; 
        genesis.nNonce = 4314804; 
 
     
       // hashGenesisBlock = genesis.GetHash(); 
       // assert(hashGenesisBlock == uint256("0x0000069359d0865762d8be44397c148fe34cc3b9403d5667537e33fbaea2a8c9")); 
 
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
        // Testnet adeptio BIP32 pubkeys start with 'DRKV' 
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >(); 
        // Testnet adeptio BIP32 prvkeys start with 'DRKP' 
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >(); 
        // Testnet adeptio BIP44 coin type is '1' (All coin's testnet default) 
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >(); 
 
        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test)); 
 
        fMiningRequiresPeers = true; 
        fAllowMinDifficultyBlocks = true; 
        fDefaultConsistencyChecks = false; 
        fRequireStandard = true; 
        fMineBlocksOnDemand = false; 
        fTestnetToBeDeprecatedFieldRPC = true; 
 
        nPoolMaxTransactions = 2; 
        nBudgetCycleBlocks = 144; //!< Ten cycles per day on testnet 
        strSporkKey = "04A8B319388C0F8588D238B9941DC26B26D3F9465266B368A051C5C100F79306A557780101FE2192FE170D7E6DEFDCBEE4C8D533396389C0DAFFDBC842B002243C"; 
        strSporkKeyOld = "04348C2F50F90267E64FACC65BFDC9D0EB147D090872FB97ABAE92E9A36E6CA60983E28E741F8E7277B11A7479B626AC115BA31463AC48178A5075C5A9319D4A38"; 
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox"; 
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT 
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short 
                                       // here because we only have a 8 block finalization window on testnet 
 
        nProposalEstablishmentTime = 60 * 5; // Proposals must be at least 5 mns old to make it into a test budget 
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
        nDefaultPort = 19077;
        assert(hashGenesisBlock == uint256("0x05ec3f4d9992323d64f4cba4f6ac0079b69277cfc0834a0d6d959fe9ff86b89c"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

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
