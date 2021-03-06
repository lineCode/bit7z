/*
 * bit7z - A C++ static library to interface with the 7-zip DLLs.
 * Copyright (c) 2014-2019  Riccardo Ostani - All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * Bit7z is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with bit7z; if not, see https://www.gnu.org/licenses/.
 */

#ifndef STREAMEXTRACTCALLBACK_HPP
#define STREAMEXTRACTCALLBACK_HPP

#include <vector>
#include <map>

#include "../include/bittypes.hpp"
#include "../include/extractcallback.hpp"

namespace bit7z {
    using std::vector;
    using std::map;
    using std::ostream;

    class StreamExtractCallback : public ExtractCallback {
        public:
            StreamExtractCallback( const BitArchiveHandler& handler,
                                   const BitInputArchive& inputArchive,
                                   ostream& outputStream );

            virtual ~StreamExtractCallback() override;

            wstring getErrorMessage() const override;

            // IArchiveExtractCallback
            STDMETHOD( GetStream )( UInt32 index, ISequentialOutStream** outStream, Int32 askExtractMode );
            STDMETHOD( SetOperationResult )( Int32 resultEOperationResult );

        private:
            ostream& mOutputStream;
            CMyComPtr< IOutStream > mStdOutStream;
    };
}
#endif // STREAMEXTRACTCALLBACK_HPP
