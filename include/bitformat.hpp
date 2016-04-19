#ifndef BITFORMAT
#define BITFORMAT

#include <bitset>
#include <string>

#include "../include/bitguids.hpp"

#define FEATURES_COUNT 6

namespace bit7z {
    using std::wstring;
    using std::bitset;

    enum FormatFeatures {
        MULTIPLE_FILES    = 1 << 0, /* 2^0 = 1  = 000001 */
        SOLID_ARCHIVE     = 1 << 1, /* 2^1 = 2  = 000010 */
        COMPRESSION_LEVEL = 1 << 2, /* 2^2 = 4  = 000100 */
        ENCRYPTION        = 1 << 3, /* 2^3 = 8  = 001000 */
        HEADER_ENCRYPTION = 1 << 4, /* 2^4 = 16 = 010000 */
        INMEM_COMPRESSION = 1 << 5, /* 2^5 = 32 = 100000 */
    };

    /**
     * @brief The BitInFormat class specifies the extractable archive formats
     */
    class BitInFormat {
        public:
            BitInFormat( unsigned char value );

            int value() const;

            bool operator==( BitInFormat const &other ) const;
            bool operator!=( BitInFormat const &other ) const;

            const GUID guid() const;


        private:
            const unsigned char mValue;
    };

    /**
     * @brief The BitInOutFormat class specifies the formats available for creating new archives and extract old ones
     */
    class BitInOutFormat : public BitInFormat {
        public:
            BitInOutFormat( unsigned char value, const wstring &ext, bitset< FEATURES_COUNT > features );

            const wstring                 &extension() const;
            const bitset< FEATURES_COUNT > features() const;
            bool hasFeature( FormatFeatures feature ) const;

        private:
            const wstring mExtension;
            const bitset< FEATURES_COUNT > mFeatures;
    };

    namespace BitFormat {
        extern const BitInFormat Rar, Arj, Z, Lzh, Cab, Nsis, Lzma, Lzma86, Ppmd, TE, UEFIc, UEFIs, SquashFS,
                                     CramFS, APM, Mslz, Flv, Swf, Swfc, Ntfs, Fat, Mbr, Vhd, Pe, Elf, Macho, Udf, Xar,
                                     Mub, Hfs, Dmg, Compound, Iso, Chm, Split, Rpm, Deb, Cpio;

        extern const BitInOutFormat Zip, BZip2, SevenZip, Xz, Wim, Tar, GZip;
    };
}
#endif // BITFORMAT
