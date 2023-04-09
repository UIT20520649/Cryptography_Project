#include "cryptopp/osrng.h"
using CryptoPP::byte;
using CryptoPP::SecByteBlock;

#include <string>
using std::string;
using std::wstring;

#include <string>
using std::string;
using std::wstring;

#include <cstdlib>
using std::exit;

#include "cryptopp/cryptlib.h"
using CryptoPP::Exception;

#include "cryptopp/hex.h"
using CryptoPP::HexDecoder;
using CryptoPP::HexEncoder;

#include "cryptopp/filters.h"
using CryptoPP::ArraySink;
using CryptoPP::AuthenticatedDecryptionFilter;
using CryptoPP::AuthenticatedEncryptionFilter;
using CryptoPP::Redirector; 
using CryptoPP::StreamTransformationFilter;
using CryptoPP::StringSink;
using CryptoPP::StringSource;
#include "cryptopp/aes.h"
using CryptoPP::AES;

#include "cryptopp/ccm.h"
using CryptoPP::CBC_Mode;
using CryptoPP::CCM;
using CryptoPP::CFB_Mode;
using CryptoPP::CTR_Mode;
using CryptoPP::ECB_Mode;
using CryptoPP::OFB_Mode;
#include <cryptopp/xts.h>
using CryptoPP::XTS;
#include <cryptopp/gcm.h>
using CryptoPP::GCM;


#include <iostream>
using std::cerr;
using std::endl;
using std::wcerr;
using std::wcin;
using std::wcout;

#include <cryptopp/osrng.h>
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/files.h"
using CryptoPP::BufferedTransformation;
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include <iostream>
using std::cerr;
using std::endl;
using std::wcin;
using std::wcout;
using std::cout;

#include <assert.h>

//Cài _setmode()/
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#else
#endif
//Chuyển wstring
#include <locale>
using std::wstring_convert;
#include <codecvt>
using std::codecvt_utf8;

//Chuyển từ string sang wstring
wstring string_to_wstring(const std::string &str)
{
    wstring_convert<codecvt_utf8<wchar_t>> towstring;
    return towstring.from_bytes(str);
}

enum class MODE
{
    ECB,
    CBC,
    OFB,
    CFB,
    CTR,
    XTS,
    CCM,
    GCM
};
class AESProgram
{
    ECB_Mode<AES>::Encryption ECB_ENC;
    ECB_Mode<AES>::Decryption ECB_DEC;

    CBC_Mode<AES>::Encryption CBC_ENC;
    CBC_Mode<AES>::Decryption CBC_DEC;

    OFB_Mode<AES>::Encryption OFB_ENC;
    OFB_Mode<AES>::Decryption OFB_DEC;

    CFB_Mode<AES>::Encryption CFB_ENC;
    CFB_Mode<AES>::Encryption CFB_DEC;

    CTR_Mode<AES>::Encryption CTR_ENC;
    CTR_Mode<AES>::Encryption CTR_DEC;

    XTS<AES>::Encryption XTS_ENC;
    XTS<AES>::Encryption XTS_DEC;

    CCM<AES, 16>::Encryption CCM_ENC;
    CCM<AES, 16>::Encryption CCM_DEC;

    GCM<AES>::Encryption GCM_ENC;
    GCM<AES>::Decryption GCM_DEC;
public:
    //ECB mode
    void Encryption_ECB(string &cipher, const string &plain, const SecByteBlock &key)
    {
        ECB_ENC.SetKey(key, key.size());
        StringSource ss(plain, true, new StreamTransformationFilter(ECB_ENC, new StringSink(cipher)));
    }
    void Decryption_ECB(string &cipher, const string &plain, const SecByteBlock &key)
    {
        ECB_DEC.SetKey(key, key.size());
        StringSource ss(plain, true, new StreamTransformationFilter(ECB_DEC, new StringSink(cipher)));
    }

    //CBC mode
    void Encryption_CBC(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        CBC_ENC.SetKeyWithIV(key, key.size(), iv);
        StringSource ss(plain, true, new StreamTransformationFilter(CBC_ENC, new StringSink(cipher)));
    }
    void Decryption_CBC(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        CBC_DEC.SetKeyWithIV(key, key.size(), iv);
        StringSource ss(plain, true, new StreamTransformationFilter(CBC_DEC, new StringSink(cipher)));
    }

    //OFB mode
    void Encryption_OFB(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        OFB_ENC.SetKeyWithIV(key, key.size(), iv);
        StringSource ss(plain, true, new StreamTransformationFilter(OFB_ENC, new StringSink(cipher)));
    }
    void Decryption_OFB(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        OFB_DEC.SetKeyWithIV(key, key.size(), iv);
        StringSource ss(plain, true, new StreamTransformationFilter(OFB_DEC, new StringSink(cipher)));
    }

    //CFB mode
    void Encryption_CFB(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        CFB_ENC.SetKeyWithIV(key, key.size(), iv);
        StringSource ss(plain, true, new StreamTransformationFilter(CFB_ENC, new StringSink(cipher)));
    }
    void Decryption_CFB(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        CFB_DEC.SetKeyWithIV(key, key.size(), iv);
        StringSource ss(plain, true, new StreamTransformationFilter(CFB_DEC, new StringSink(cipher)));
    }

    //CTR mode
    void Encryption_CTR(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        CTR_ENC.SetKeyWithIV(key, key.size(), iv);
        StringSource ss(plain, true, new StreamTransformationFilter(CTR_ENC, new StringSink(cipher)));
    }
    void Decryption_CTR(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        CTR_DEC.SetKeyWithIV(key, key.size(), iv);
        StringSource ss(plain, true, new StreamTransformationFilter(CTR_DEC, new StringSink(cipher)));
    }

    //XTS mode
    void Encryption_XTS(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        XTS_ENC.SetKeyWithIV(key, key.size(), iv);
        StringSource ss(plain, true, new StreamTransformationFilter(XTS_ENC, new StringSink(cipher), StreamTransformationFilter::NO_PADDING));
    }
    void Decryption_XTS(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        XTS_DEC.SetKeyWithIV(key, key.size(), iv);
        StringSource ss(plain, true, new StreamTransformationFilter(XTS_DEC, new StringSink(cipher), StreamTransformationFilter::NO_PADDING));
    }

    //CCM mode
    void Encryption_CCM(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        CCM_ENC.SetKeyWithIV(key, key.size(), iv);
        CCM_ENC.SpecifyDataLengths(0, plain.length(), 0);
        StringSource ss(plain, true, new AuthenticatedEncryptionFilter(CCM_ENC, new StringSink(cipher)));
    }
    void Decryption_CCM(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv)
    {
        CCM_DEC.SetKeyWithIV(key, key.size(), iv);
        CCM_ENC.SpecifyDataLengths(0, plain.length() - 16, 0);
        StringSource ss(plain, true, new AuthenticatedDecryptionFilter(CCM_DEC, new StringSink(cipher)));
    }

    //GCM mode
    void Encryption_GCM(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv){
        GCM_ENC.SetKeyWithIV(key,key.size(),iv);
        const int TAG_SIZE = 12;
        GCM_ENC.SpecifyDataLengths(0,plain.length(),0);
        StringSource ss( plain, true,new AuthenticatedEncryptionFilter( GCM_ENC,new StringSink(cipher), false, TAG_SIZE)); 
    }
    void Decryption_GCM(string &cipher, const string &plain, const SecByteBlock &key, const SecByteBlock &iv){
        GCM_DEC.SetKeyWithIV(key,key.size(),iv);
        const int TAG_SIZE = 12;
        AuthenticatedDecryptionFilter df( GCM_DEC,new StringSink(cipher), TAG_SIZE); 
        StringSource ss(plain, true,new Redirector(df)); 
    }

    string ConverHex(const string &text)
    {
        string encoded;
        encoded.clear();
        StringSource(text, true, new HexEncoder(new StringSink(encoded))); // HexEncoder
        return encoded;
    }
    string Encryption(const string &plain, MODE CipherMode, const SecByteBlock &key, const SecByteBlock &iv)
    {
        string cipher;
        try
        {
            switch (CipherMode)
            {
            case MODE::ECB:
                Encryption_ECB(cipher, plain, key);
                break;
            case MODE::CBC:
                Encryption_CBC(cipher, plain, key, iv);
                break;
            case MODE::OFB:
                Encryption_OFB(cipher, plain, key, iv);
                break;
            case MODE::CFB:
                Encryption_CFB(cipher, plain, key, iv);
                break;
            case MODE::CTR:
                Encryption_CTR(cipher, plain, key, iv);
                break;
            case MODE::XTS:
                Encryption_XTS(cipher, plain, key, iv);
                break;
            case MODE::CCM:
                Encryption_CCM(cipher, plain, key, iv);
                break;
            case MODE::GCM:
                Encryption_GCM(cipher, plain, key, iv);
                break;
            default:
                cerr << "Not recognizing this mode!" << endl;
                exit(1); // StringSource
            }
        }
        catch (const CryptoPP::Exception &e)
        {
            cerr << e.what() << endl;
            exit(1);
        }
        return cipher;
    }
    string Decryption(const string &cipher, MODE CipherMode, const SecByteBlock &key, const SecByteBlock &iv)
    {
        string recovered;
        try
        {
            switch (CipherMode)
            {
            case MODE::ECB:
                Decryption_ECB(recovered, cipher, key);
                break;
            case MODE::CBC:
                Decryption_CBC(recovered, cipher, key, iv);
                break;
            case MODE::OFB:
                Decryption_OFB(recovered, cipher, key, iv);
                break;
            case MODE::CFB:
                Decryption_CFB(recovered, cipher, key, iv);
                break;
            case MODE::CTR:
                Decryption_CTR(recovered, cipher, key, iv);
                break;
            case MODE::XTS:
                Decryption_XTS(recovered, cipher, key, iv);
                break;
            case MODE::CCM:
                Decryption_CCM(recovered, cipher, key, iv);
                break;
            case MODE::GCM:
                Decryption_GCM(recovered, cipher, key, iv);
            default:
                cerr << "Not recognizing this mode!" << endl;
                exit(1); // StringSource
            }
        }
        catch (const CryptoPP::Exception &e)
        {
            cerr << e.what() << endl;
            exit(1);
        }
        return recovered;
    }
};
//Chuyển từ wstring sang string
string wstring_to_string(const std::wstring &str)
{
    wstring_convert<codecvt_utf8<wchar_t>> tostring;
    return tostring.to_bytes(str);
}

void PrintByte(const SecByteBlock &message)
{
    string encoded;
    StringSource(message, message.size(), true, new HexEncoder(new StringSink(encoded)));
    wcout << string_to_wstring(encoded) << endl;
}
string ConvertHex(const string &text)
{
    string encoded;
    encoded.clear();
    StringSource(text, true, new HexEncoder(new StringSink(encoded)));
    return encoded;
}

void Encrypt_Process(AESProgram &prog, MODE CipherMode, string plain, string &_cipher, SecByteBlock _key, SecByteBlock _iv)
{
    SecByteBlock key;
    SecByteBlock iv(AES::BLOCKSIZE);
    string cipher, encoded;
    wcout << string_to_wstring(plain) << endl;
    key = _key;
    if (CipherMode != MODE::ECB)
        iv = _iv;
    cipher = prog.Encryption(plain, CipherMode, key, iv);
    encoded = ConvertHex(cipher);
    _cipher = ConvertHex(cipher);
    wcout << "Ciphertext: " << string_to_wstring(encoded) << endl;
}
void Decrypt_Process(AESProgram &prog, MODE CipherMode, string _cipher, SecByteBlock _key, SecByteBlock _iv)
{
    SecByteBlock key;
    SecByteBlock iv(AES::BLOCKSIZE);
    string plain, encoded,cipher;
    encoded = _cipher;
    StringSource(encoded, true, new HexDecoder(new StringSink(cipher)));
    wcout << string_to_wstring(plain) << endl;
    key = _key;
    if (CipherMode != MODE::ECB)
        iv = _iv;
    plain = prog.Decryption(cipher, CipherMode, key, iv);
    if(CipherMode == MODE::XTS){
        cout << "Recover text: " << plain << endl;
        return;
    }
    wcout << "Recover text: " << string_to_wstring(plain) << endl;
}

int main(){
    setlocale(LC_ALL, "");

    AESProgram prog;
    MODE AES_Mode;

    // Random Key and IV
    AutoSeededRandomPool prng;
    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    prng.GenerateBlock(key,key.size());
    SecByteBlock iv(AES::BLOCKSIZE);
    prng.GenerateBlock(iv,iv.size());
    wcout << "KEY : ";
    PrintByte(key);
    wcout << "IV : ";
    int temp;
    string plaintext;
    string cipher, recovered, encoded;
    wcout<<"~~~~~~~~~~~~~~~~~Welcome to the AES~~~~~~~~~~~~~~~~~~~\n";
    wcout << "1.CBC Mode ------------------------\n";
    wcout << "2.ECB Mode ------------------------\n";
    wcout << "3.OFB Mode ------------------------\n";
    wcout << "4.CFB Mode ------------------------\n";
    wcout << "5.CTR Mode ------------------------\n";
    wcout << "6.XTS Mode ------------------------\n";
    wcout << "7.CCM Mode ------------------------\n";
    wcout << "8.GCM Mode ------------------------\n";
    wcout << "8.GCM Mode ------------------------\n";
    wcout<<"Enter mode: ";
    wcin>>temp;
    switch (temp)
    {
    case 1:
        wcout << "1.CBC Mode-------------------------\n";
        plaintext = "CBC Mode Test";
        wcout << "Plaintext : " << string_to_wstring(plaintext) << endl;
        AES_Mode = MODE::CBC;
        Encrypt_Process(prog,AES_Mode,plaintext,cipher,key,iv);
        Decrypt_Process(prog,AES_Mode,cipher,key,iv);
        wcout << "-----------------------------------------------------------\n\n";
        break;
    case 2:
        wcout << "2.ECB Mode --------------------------\n";
        plaintext = "ECB Mode Test";
        wcout << "Plaintext : " << string_to_wstring(plaintext) << endl;
        AES_Mode = MODE::ECB;
        Encrypt_Process(prog,AES_Mode,plaintext,cipher,key,iv);
        Decrypt_Process(prog,AES_Mode,cipher,key,iv);
        wcout << "-----------------------------------------------------------\n\n";
        break;
    case 3:
        wcout << "3. OFB Mode----------------------------\n";
        plaintext = "OFB Mode Test";
        wcout << "Plaintext : " << string_to_wstring(plaintext) << endl;
        AES_Mode = MODE::OFB;
        Encrypt_Process(prog,AES_Mode,plaintext,cipher,key,iv);
        Decrypt_Process(prog,AES_Mode,cipher,key,iv);
        wcout << "-----------------------------------------------------------\n\n";
        break;
    case 4:
        wcout << "4.CFB Mode ------------------------------\n";
        plaintext = "CFB Mode Test";
        wcout << "Plaintext : " << string_to_wstring(plaintext) << endl;
        AES_Mode = MODE::CFB;
        Encrypt_Process(prog,AES_Mode,plaintext,cipher,key,iv);
        Decrypt_Process(prog,AES_Mode,cipher,key,iv);
        wcout << "-----------------------------------------------------------\n\n";
        break;
    case 5:
        wcout << "5.CTR Mode -------------------------------\n";
        plaintext = "CTR Mode Test";
        wcout << "Plaintext : " << string_to_wstring(plaintext) << endl;
        AES_Mode = MODE::CTR;
        Encrypt_Process(prog,AES_Mode,plaintext,cipher,key,iv);
        Decrypt_Process(prog,AES_Mode,cipher,key,iv);
        wcout << "-----------------------------------------------------------\n\n";
        break;
    case 6:
        wcout << "6.XTS Mode ---------------------------------\n";
        SecByteBlock xts_key(32);
        prng.GenerateBlock(xts_key,xts_key.size());
        plaintext = "XTS Mode Test";
        wcout << "Plaintext : " << string_to_wstring(plaintext) << endl;
        AES_Mode = MODE::CTR;
        Encrypt_Process(prog,AES_Mode,plaintext,cipher,xts_key,iv);
        Decrypt_Process(prog,AES_Mode,cipher,xts_key,iv);
        wcout << "-----------------------------------------------------------\n\n";
        break;
    case 7:
        wcout << "7.CCM Mode -----------------------------------\n";
        plaintext = "CCM Mode Test";
        wcout << "Plaintext : " << string_to_wstring(plaintext) << endl;
        AES_Mode = MODE::CTR;
        Encrypt_Process(prog,AES_Mode,plaintext,cipher,key,iv);
        Decrypt_Process(prog,AES_Mode,cipher,key,iv);
        wcout << "-----------------------------------------------------------\n\n";
        break;
    case 8:
        wcout << "8.GCM Mode---------------------------------\n";
        plaintext = "GCM Mode Test";
        wcout << "Plaintext : " << string_to_wstring(plaintext) << endl;
        AES_Mode = MODE::GCM;
        Encrypt_Process(prog,AES_Mode,plaintext,cipher,key,iv);
        Decrypt_Process(prog,AES_Mode,cipher,key,iv);
        wcout << "-----------------------------------------------------------\n\n";
    default:
        break;
    }

}
