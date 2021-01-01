//============================================================================
//
//   SSSS    tt          lll  lll       
//  SS  SS   tt           ll   ll        
//  SS     tttttt  eeee   ll   ll   aaaa 
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2007 by Bradford W. Mott and the Stella team
//
// See the file "license" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//
// $Id: SoundNull.cxx,v 1.6 2007/01/01 18:04:40 stephena Exp $
//============================================================================

#include "emucore/Serializer.hxx"
#include "emucore/Deserializer.hxx"

#include "emucore/bspf/bspf.hxx"

#include "emucore/OSystem.hxx"
#include "emucore/Settings.hxx"
#include "common/SoundNull.hxx"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
SoundNull::SoundNull(OSystem* osystem)
    : Sound(osystem)
{
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
SoundNull::~SoundNull()
{
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool SoundNull::load(Deserializer& in)
{
  std::string soundDevice = "TIASound";
  if(in.getString() != soundDevice)
    return false;

  uInt8 reg;
  reg = (uInt8) in.getInt();
  reg = (uInt8) in.getInt();
  reg = (uInt8) in.getInt();
  reg = (uInt8) in.getInt();
  reg = (uInt8) in.getInt();
  reg = (uInt8) in.getInt();

  // myLastRegisterSetCycle
  in.getInt();

  return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool SoundNull::save(Serializer& out)
{
  out.putString("TIASound");

  uInt8 reg = 0;
  out.putInt(reg);
  out.putInt(reg);
  out.putInt(reg);
  out.putInt(reg);
  out.putInt(reg);
  out.putInt(reg);

  // myLastRegisterSetCycle
  out.putInt(0);

  return true;
}
