// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//
// Main network
//
class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x00;
        pchMessageStart[1] = 0xa1;
        pchMessageStart[2] = 0x99;
        pchMessageStart[3] = 0x9f;
        vAlertPubKey = ParseHex("7ceef1ea113f123756b659c91a56897eba2efaacb6a192acdbef7894465f81f85d131aadfef3be6145678454852a2d08c6314bba5ca3cbe5616262da3b1a6ebba");
        nDefaultPort = 32623; // peer
        nRPCPort = 32624; // rpc
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 19);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 16);

        const char* pszTimestamp = "Burger King Considers Accepting Dogecoin (DOGE) Payments. Shiba Inu (SHIB) and TMS Network (TMSN) Bounce on News | Null Transaction PR | TheMerkle.com | April 5, 2023";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].nValue = 1 * COIN;
        vout[0].SetEmpty();
        CTransaction txNew(1, 1680658111, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1680658111;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 651389;

        /** Genesis Block MainNet */
        /*
            Hashed MainNet Genesis Block Output
            block.hashMerkleRoot == 73c5bd3c8195f0dc10c72fdcabbf599d174a1df352a6f934583fd70f0f8ea006
            block.nTime = 1680658111
            block.nNonce = 651389
            block.GetHash = 000015650af3ea2bfe535f26a0d64771d87c23273672cc974c93223df9f8e8b4
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000015650af3ea2bfe535f26a0d64771d87c23273672cc974c93223df9f8e8b4"));
        assert(genesis.hashMerkleRoot == uint256("0x73c5bd3c8195f0dc10c72fdcabbf599d174a1df352a6f934583fd70f0f8ea006"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,90);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,82);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,84);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,79);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        // vSeeds.push_back(CDNSSeedData("node0",  "000.000.000.000"));

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nPoolMaxTransactions = 9;
        strMNenginePoolDummyAddress = "";
        strDevOpsAddress = "";
        strPASfeeAddress = "";
        nEndPoWBlock = 0x7fffffff;
        nStartPoSBlock = 1;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x00;
        pchMessageStart[1] = 0xa1;
        pchMessageStart[2] = 0x99;
        pchMessageStart[3] = 0x9f;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 14);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 14);
        vAlertPubKey = ParseHex("7ceef1ea113f123756b659c91a56897eba2efaacb6a192acdbef7894465f81f85d131aadfef3be6145678454852a2d08c6314bba5ca3cbe5616262da3b1a6ebba");
        nDefaultPort = 32620; // peer
        nRPCPort = 32621; // rpc
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime  = 1680658119;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 5158;

        /** Genesis Block TestNet */
        /*
            Hashed TestNet Genesis Block Output
            block.hashMerkleRoot == 73c5bd3c8195f0dc10c72fdcabbf599d174a1df352a6f934583fd70f0f8ea006
            block.nTime = 1680658119
            block.nNonce = 5158
            block.GetHash = 00023b3da99e91a27d33c172b14d3154f3f0a5efd5d0977e0a67ae88f8173d4f
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00023b3da99e91a27d33c172b14d3154f3f0a5efd5d0977e0a67ae88f8173d4f"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,91); //
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,42); //
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,39); //
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,52); //
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        nEndPoWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xa8;
        pchMessageStart[1] = 0xf8;
        pchMessageStart[2] = 0x8c;
        pchMessageStart[3] = 0xff;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1680658121;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 8;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 20009; //
        strDataDir = "regtest";

        /** Genesis Block RegNet */
        /*
            Hashed RegNet Genesis Block Output
            block.hashMerkleRoot == 73c5bd3c8195f0dc10c72fdcabbf599d174a1df352a6f934583fd70f0f8ea006
            block.nTime = 1680658121
            block.nNonce = 8
            block.GetHash = a254381d50bbd6e94cacd9de853bcbca16692d811f82421ac85ffa9d0e1d894a
        */

        assert(hashGenesisBlock == uint256("0xa254381d50bbd6e94cacd9de853bcbca16692d811f82421ac85ffa9d0e1d894a"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
