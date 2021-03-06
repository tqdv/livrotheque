/* /////////////////////////////////////////////////////////////////////////////
 * File:        example.cpp.1.cpp
 *
 * Purpose:     Implementation file for the example.cpp.1 project.
 *
 * Created:     27th April 2006
 * Updated:     15th March 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2006-2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 *              This source code is placed into the public domain 2006
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software. 
 *
 *              This source code is provided by Synesis Software Pty Ltd "as is"
 *              and any warranties, whether expressed or implied, including, but
 *              not limited to, the implied warranties of merchantability and
 *              fitness for a particular purpose are disclaimed. In no event
 *              shall the Synesis Software Pty Ltd be liable for any direct,
 *              indirect, incidental, special, exemplary, or consequential
 *              damages (including, but not limited to, procurement of
 *              substitute goods or services; loss of use, data, or profits; or
 *              business interruption) however caused and on any theory of
 *              liability, whether in contract, strict liability, or tort
 *              (including negligence or otherwise) arising in any way out of
 *              the use of this software, even if advised of the possibility of
 *              such damage. 
 *
 *              Neither the name of Synesis Software Pty Ltd nor the names of
 *              any subdivisions, employees or agents of Synesis Software Pty
 *              Ltd, nor the names of any other contributors to this software
 *              may be used to endorse or promote products derived from this
 *              software without specific prior written permission. 
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* b64 Header Files */
#include <b64/b64.hpp>
#include <b64/implicit_link.h>  /* Don't include this if you want to use explicit linking */

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

/* Standard C Header Files */
#include <assert.h>
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////////// */

int main(int /* argc */, char ** /*argv*/)
{
    /* Simple conversion using encode() and decode(). */

    try
    {
        /* Declare an array of ints to use as the 'binary' blob to encode. */
        int                 ints[]  =   { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        /* Perform the encoding, whose results are returned in an instance of
         * b64::cpp::string_t.
         */
        b64::cpp::string_t  enc =   b64::cpp::encode(&ints[0], sizeof(ints));

        std::cout << "Converted: [" << enc << "]" << std::endl;

        /* Perform the decoding, whose results are returned in an instance of
         * b64::cpp::blob_t.
         */
        b64::cpp::blob_t    dec =   b64::cpp::decode(enc);

        /* Verify that the decoding is exactly the same size and contents as 
         * the encoding.
         */
        assert(0 == ::memcmp(&ints[0], &dec[0], sizeof(ints)));
    }
    catch(b64::cpp::coding_exception &x)
    {
        std::cerr << "Exception: " << x.what() << std::endl;
    }

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////////// */
