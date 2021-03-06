// Part of SimCoupe - A SAM Coupe emulator
//
// BlueAlpha.cpp: Blue Alpha Sampler
//
//  Copyright (c) 1999-2012 Simon Owen
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef BLUEALPHA_H
#define BLUEALPHA_H

#include "IO.h"

#define BLUE_ALPHA_CLOCK_TIME   (REAL_TSTATES_PER_SECOND/pBlueAlpha->GetClockFreq()/2)    // half period

class CBlueAlphaDevice final : public CIoDevice
{
    public:
        CBlueAlphaDevice ();

    public:
        void Reset () override;

        BYTE In (WORD wPort_) override;
        void Out (WORD wPort_, BYTE bVal_) override;

    public:
        int GetClockFreq ();
        bool Clock ();

    protected:
        BYTE m_bControl = 0;
        BYTE m_bPortA = 0;
        BYTE m_bPortB = 0;
        BYTE m_bPortC = 0;
};

extern CBlueAlphaDevice *pBlueAlpha;

#endif  // BLUEALPHA_H
