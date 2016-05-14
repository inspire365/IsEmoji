#include <iostream>
#include <inttypes.h>
#include <string>

using namespace std;


// emoji code points taken from : http://apps.timwhitlock.info/emoji/tables/unicode
bool IsEmoji(const char* ch, uint32_t len, uint32_t* pos)
{
  if(ch == NULL || len < 2)
    return false;

  const uint8_t* buf = (const uint8_t*)ch;

  // -----------------  table 1 ----------------
  // 4 bufars
  if(pos != NULL) *pos = 4;
  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x98 && (buf[3] >= 0x81 && buf[3] <= 0xBF))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x99 && buf[3] == 0x80)
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x99 && (buf[3] >= 0x85 && buf[3] <= 0x8F))
    return true;

  // ----------------- table 2 -----------------
  if(pos != NULL) *pos = 3;
  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x9C && (buf[2] >= 0x82 && buf[2] <= 0x8F))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x9C && (buf[2] == 0x92 || buf[2] == 0x94 || \
     buf[2] == 0x96 || buf[2] == 0xA8 || buf[2] == 0xB3 || buf[2] == 0xB4))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x9D && (buf[2] == 0x84 || buf[2] == 0x87 || \
     buf[2] == 0x8C || buf[2] == 0x8E || buf[2] == 0x93 || buf[2] == 0x94 || \
     buf[2] ==0x95 || buf[2] == 0x97 || buf[2] == 0xA4))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x9E && (buf[2] == 0x95 || buf[2] == 0x96 || \
     buf[2] == 0x97 || buf[2] == 0xA1 || buf[2] == 0xB0))
    return true;

  // ----------------- table 3 --------------------
  *pos = 4;
  if(len > 3 && buf[0] ==0xF0 && buf[1] == 0x9F && buf[2] == 0x9A && (buf[3] == 0x80 || buf[3] == 0x83 || \
     buf[3] == 0x84 || buf[3] == 0x85 || buf[3] == 0x87 || buf[3] == 0x89 || buf[3] == 0x8C || buf[3] == 0x8F || \
     buf[3] == 0x91 || buf[3] == 0x92 || buf[3] == 0x95 || buf[3] == 0x97 || buf[3] == 0x99 || buf[3] == 0x9A || \
     buf[3] == 0xA2 || buf[3] == 0xA4 || buf[3] == 0xA5 || buf[3] == 0xA7 || buf[3] == 0xA8 || buf[3] == 0xA9 || \
     buf[3] == 0xAA || buf[3] == 0xAB || buf[3] == 0xAC || buf[3] == 0xAD || buf[3] == 0xB2 || buf[3] == 0xB6 || \
     buf[3] == 0xB9 || buf[3] == 0xBA || buf[3] == 0xBB || buf[3] == 0xBC || buf[3] == 0xBD || buf[3] == 0xBE ))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x9B && buf[3] == 0x80)
    return true;

  // ---------------- table 4 -------------------------
  *pos = 3;
  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x93 && buf[2] == 0x82)
    return true;

  *pos = 4;
  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x85 && (buf[3] == 0xB0 || buf[3] == 0xB1 || buf[3] == 0xBE || buf[3] == 0xBF))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x86 && (buf[3] == 0x8E || (buf[3] >= 0x91 && buf[3] <=0x9A)))
    return true;

  *pos = 8;
  if(len > 7 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x87 && buf[4] == 0xF0 && buf[5] == 0x9F && buf[6] == 0x87)
  {
    if((buf[3] == 0xA9 && buf[7] == 0xAA) || (buf[3] == 0xAC && buf[7] == 0xA7) || (buf[3] == 0xA8 && buf[7] == 0xB3) || \
       (buf[3] == 0xAF && buf[7] == 0xB5) || (buf[3] == 0xB0 && buf[7] == 0xB7) || (buf[3] == 0xAB && buf[7] == 0xB7) || \
       (buf[3] == 0xAA && buf[7] == 0xB8) || (buf[3] == 0xAE && buf[7] == 0xB9) || (buf[3] == 0xBA && buf[7] == 0xB8) || (buf[3] == 0xB7 && buf[7] == 0xBA))
      return true;
  }

  *pos = 4;
  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x88 && (buf[3] == 0x81 || buf[3] ==0x82 || buf[3] == 0x9A || buf[3] == 0xAF || \
     (buf[3] >= 0xB2 && buf[3] <= 0xBA) || buf[3] == 0x90 || buf[3] == 0x91))
    return true;

  // ------------------ table 5 ------------------------
  *pos = 2;
  if(len > 1 && buf[0] == 0xC2 && (buf[1] == 0xA9 || buf[1] == 0xAE))
    return true;

  *pos = 3;
  if(len > 2 && buf[0] == 0xE2 && ( (buf[1] == 0x80 && buf[2] == 0xBC) || (buf[1] == 0x81 && buf[2] == 0x89) ) )
    return true;

  *pos = 4;
  if(len > 3 && buf[1] == 0xE2 && buf[2] == 0x83 && buf[3] == 0xA3 && ((buf[0] >= 0x30 && buf[0] <= 0x39) || buf[0] == 0x23))
    return true;

  *pos = 3;
  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x84 && (buf[2] == 0xA2 || buf[2] == 0xB9))
    return true;

  if(len > 2 && buf[0]== 0xE2 && buf[1] == 0x86 && ( (buf[2] >= 0x94 && buf[2] <= 0x99) || buf[2] == 0xA9 || buf[2] == 0xAA))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x8C && (buf[2] == 0x9A || buf[2] == 0x9B))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x8F && ((buf[2] >= 0xA9 && buf[2] <= 0xAC) || buf[2] == 0xB0 || buf[2] == 0xB3))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x96 && (buf[2] == 0xAA || buf[2] == 0xAB || buf[2] == 0xB6))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x97 && (buf[2] == 0x80 || buf[2] == 0xBB || buf[2] == 0xBC || buf[2] == 0xBD || buf[2] == 0xBE))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x98 && (buf[2] == 0x80 || buf[2] == 0x81 || buf[2] == 0x8E || buf[2] == 0x91 || buf[2] == 0x94 || \
     buf[2] == 0x95 || buf[2] == 0x9D || buf[2] == 0xBA))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x99 && ((buf[2] >= 0x88 && buf[2] <= 0x93) || buf[2] == 0xA0 || buf[2] == 0xA3 || buf[2] == 0xA5 || \
     buf[2] == 0xA6 || buf[2] == 0xA8 || buf[2] == 0xBB || buf[2] == 0xBF))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x9A && (buf[2] == 0x93 || buf[2] == 0xA0 || buf[2] == 0xA1 || buf[2] == 0xAA || buf[2] == 0xAB || \
     buf[2] == 0xBD || buf[2] == 0xBE))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0x9B && (buf[2] == 0x84 || buf[2] == 0x85 || buf[2] == 0xBE || buf[2] == 0x94 || buf[2] == 0xAA || \
     buf[2] == 0xB2 || buf[2] == 0xB3 || buf[2] == 0xB5 || buf[2] == 0xBA || buf[2] == 0xBD))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0xA4 && (buf[2] == 0xB4 || buf[2] == 0xB5))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0xAC && (buf[2] == 0x85 || buf[2] == 0x86 || buf[2] == 0x87 || buf[2] == 0x9B || buf[2] == 0x9C))
    return true;

  if(len > 2 && buf[0] == 0xE2 && buf[1] == 0xAD && (buf[2] == 0x90 || buf[2] == 0x95))
    return true;

  if(len > 2 && buf[0] == 0xE3 && buf[1] == 0x80 && (buf[2] == 0xB0 || buf[2] == 0xBD))
    return true;

  if(len > 2 && buf[0] == 0xE3 && buf[1] == 0x8A && (buf[2] == 0x97 || buf[2] == 0x99))
    return true;

  *pos = 4;
  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && ((buf[2] == 0x80 && buf[3] == 0x84) || (buf[2] == 0x83 || buf[2] == 0x8F)))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x8C && ((buf[3] >= 0x80 && buf[3] <= 0x8C) || buf[3] == 0x8F || buf[3] == 0x91 || \
     buf[3] == 0x93 || buf[3] == 0x94 || buf[3] == 0x95 || buf[3] == 0x99 || buf[3] == 0x9B || buf[3] == 0x9F || buf[3] == 0xA0 || \
     buf[3] == 0xB0 || buf[3] == 0xB1 || buf[3] == 0xB4 || buf[3] == 0xB5))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x8C && (buf[3] >= 0xB7 && buf[3] <= 0xBF) )
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x8D && ((buf[3] >= 0x80 && buf[3] <= 0x8A) || (buf[3] >= 0x8C && buf[3] <= 0x8F) || \
     (buf[3] >= 0x80 && buf[3] <= 0xBB)))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x8E && ( (buf[3] >= 0x80 && buf[3] <= 0x93) || (buf[3] >= 0xA0 && buf[3] <= 0xBF) ))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x8F && ( (buf[3] >= 0x80 && buf[3] <= 0x84) || buf[3] == 0x86 || buf[3] == 0x88 || buf[3] == 0x8A))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x8F && ( (buf[3] >= 0xA0 && buf[3] <= 0xA3) || (buf[3] >= 0xA5 && buf[3] <= 0xB0) ))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x90 && (buf[3] == 0x8C || buf[3] == 0x8D || buf[3] == 0x8E || buf[3] == 0x91 || \
     buf[3] == 0x92 || buf[3] == 0x94 || (buf[3] >= 0x97 && buf[3] <= 0xBE) ))
    return true;

  if(len > 3 && buf[0] ==0xF0 && buf[1] == 0x9F && buf[2] == 0x91 && (buf[3] == 0x80 || (buf[3] >= 0x82 && buf[3] <= 0xA4) || (buf[3] >= 0xA6 && buf[3] <= 0xAB) || \
     buf[3] == 0xAE || buf[3] == 0xAF || (buf[3] >= 0xB0  && buf[3] <= 0xBF)) )
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x92 && ( (buf[3] >= 0x80 && buf[3] <= 0xAC) || (buf[3] >= 0xAE && buf[3] <= 0xB5) || \
     (buf[3] >= 0xB8 && buf[3] <= 0xBF) ) )
    return true;

  if(len > 3 && buf[0] ==0xF0 && buf[1] == 0x9F && buf[2] == 0x93 && ( (buf[3] >= 0x80 && buf[3] <= 0xAB) || buf[3] == 0xAE || (buf[3] >= 0xB0 && buf[3] ==0xB4) || \
     buf[3] == 0xB6 || buf[3] == 0xB7 || buf[3] == 0xB9 || buf[3] == 0xBA || buf[3] == 0xBB || buf[3] == 0xBC) )
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x94 && ( buf[3] == 0x83 || (buf[3] >= 0x8A && buf[3] <= 0x94) || (buf[3] >= 0x96 && buf[3] <= 0xAB) || \
     (buf[3] >= 0xAE && buf[3] <= 0xBD) ))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] ==0x9F && buf[2] == 0x95 && (buf[3] >= 0x90 && buf[3] <= 0xBF))
    return true;

  // table 6a
  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] ==0x98 && (buf[3] == 0x80 || buf[3] == 0x87 || buf[3] == 0x88 || buf[3] == 0x8E || buf[3] == 0x90 || \
     buf[3] == 0x91 || buf[3] == 0x95 || buf[3] == 0x97 || buf[3] == 0x99 || buf[3] == 0x9B || buf[3] == 0x9F || buf[3] == 0xA6 || buf[3] == 0xA7 || \
     buf[3] == 0xAC || buf[3] == 0xAE || buf[3] == 0xAF || buf[3] == 0xB4 || buf[3] == 0xB6))
    return true;

  // table 6b
  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] ==0x9A && (buf[3] == 0x81 || buf[3] == 0x82 || buf[3] == 0x86 || buf[3] == 0x88 || buf[3] == 0x8A || \
     buf[3] == 0x8D || buf[3] == 0x8E || buf[3] == 0x90 || buf[3] == 0x94 || buf[3] == 0x96 || buf[3] == 0x98 || (buf[3] >= 0x9B && buf[3] <= 0x9F) || \
     buf[3] == 0xA0 || buf[3] == 0xA1 || buf[3] == 0xA3 || buf[3] == 0xA6 || buf[3] == 0xAE || buf[3] == 0xAF || buf[3] == 0xB0 || buf[3] ==0xB1 || \
     buf[3] == 0xB3 || buf[3] == 0xB4 || buf[3] == 0xB5 || buf[3] == 0xB7 || buf[3] == 0xB8 || buf[3] == 0xBF))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x9B && (buf[3] >= 0x81 && buf[3] <= 0x85))
    return true;

  // table 6c
  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x8C && (buf[3] == 0x8D || buf[3] == 0x8E || buf[3] == 0x90 || buf[3] == 0x92 || buf[3] == 0x96 || \
     buf[3] == 0x97 || buf[3] == 0x98 || buf[3] == 0x9A || buf[3] == 0x9C || buf[3] == 0x9D || buf[3] == 0x9E || buf[3] == 0xB2 || buf[3] == 0xB3))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x8D && (buf[3] == 0x8B || buf[3] == 0x90 || buf[3] == 0xBC))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x8F && (buf[3] == 0x87 || buf[3] == 0x89 || buf[3] == 0xA4))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x90 && ( (buf[3] >= 0x80 && buf[3] <= 0x8B) || buf[3] == 0x8F || buf[3] == 0x90 || \
      buf[3] == 0x93 || buf[3] == 0x95 || buf[3] == 0x96))
      return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x91 && (buf[3] == 0xA5 || buf[3] == 0xAC || buf[3] == 0xAD))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x92 && (buf[3] == 0xAD || buf[3] == 0xB6 || buf[3] == 0xB7))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x93 && (buf[3] == 0xAC || buf[3] == 0xAD || buf[3] == 0xAF || buf[3] == 0xB5))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x94 && ( (buf[3] >= 0x80 && buf[3] <= 0x82) || (buf[3] >= 0x84 && buf[3] <= 0x87) || \
     buf[3] == 0x89 || buf[3] == 0x95 || buf[3] == 0xAC || buf[3] == 0xAC || buf[3] == 0xAD))
    return true;

  if(len > 3 && buf[0] == 0xF0 && buf[1] == 0x9F && buf[2] == 0x95 && (buf[3] >= 0x9C && buf[3] <= 0xA7))
    return true;

  return false;

}

int main(int argc, char** argv)
{

  string text = "😂Hello";

  uint32_t pos = 0;
  bool status = IsEmoji(text.c_str(), text.size(), &pos);
  cout << "text: " << text << " status: " << (status ? "true" : "false") << " pos: " << pos << endl;

  text = "❎Hello";
  pos = 0;
  status = IsEmoji(text.c_str(), text.size(), &pos);
  cout << "text: " << text << " status: " << (status ? "true" : "false") << " pos: " << pos << endl;

  text = "Hello world";
  pos = 0;
  status = IsEmoji(text.c_str(), text.size(), &pos);
  cout << "text: " << text << " status: " << (status ? "true" : "false") << " pos: " << pos << endl;


  return 0;

}

