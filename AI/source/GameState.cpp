#include "Global.hpp"
#include "GameState.hpp"

#include <utility>

// GameState::GameState() {
//   m_mem_reader = MemReader::Instance();
// }

// int GameState::Stocks(int player) {
//   return m_mem_reader->ReadAddress(player - 1) >> 24;
// }

// int GameState::Percent(int player) { 
//   return m_mem_reader->ReadAddress(2 + (player - 1)) >> 16;
// }

// int GameState::CharacterID(int player) {
//   return (m_mem_reader->ReadAddress(4 + (player - 1)) & 0x0000FFFF) >> 8;
// }

// std::pair<float, float> GameState::Coordinates(int player) {
//   float x = LongToFloat(m_mem_reader->ReadAddress(6 + 2 * (player - 1)));
//   float y = LongToFloat(m_mem_reader->ReadAddress(7 + 2 * (player - 1)));
//   return std::make_pair(x, y);
// }

// int GameState::FrameCount() {
//   return m_mem_reader->ReadAddress(11) >> 16;
// }

// int GameState::StageID() {
// //  return m_mem_reader->ReadAddress(10); 
//   return 24;
// }

// int GameState::P2JumpsUsed() {
// //  return (Raw(16) & 0xFFFF0000) >> 24;
//   return 2;
// }

// long GameState::P2ActionState() {
// //  return raw_input[12];
//   return 0;
// }

// int GameState::P2Hitstun() {
// //  return LongToFloat(raw_input[18]);
//   return 0;
// }

// float GameState::P2VerticalVelocity() {
// //  return LongToFloat(raw_input[13]);
//   return 0;
// }

// int GameState::P2Hitlag() {
// // return LongToFloat(raw_input[15]);
//   return 0;
// }

// float GameState::P2ShieldSize() {
// // return LongToFloat(raw_input[17]);
//   return 0;
// }  

// bool GameState::P2InAir() {
// //  return raw_input[14];
//   return false;
// }

// //TODO: find a way to check in game without wasting time
// bool GameState::InGame() {
//   int last_frame = FrameCount();
//   GLOBAL_SLEEP(30);
//   return last_frame != FrameCount();
// }


// float GameState::LongToFloat(long n) {
//   union LongFloat {
//     long lg;
//     float fl;
//   };
//   union LongFloat ret;
//   ret.lg = n;
//   return ret.fl;
// }
