#pragma once
#include <vector>
#include <stack>
#include "SFML/Graphics.hpp"

// Default Configuration
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

// Splash State
#define SPLASH_STATE_BACKGROUND_FILEPATH "Resources/images/splash_background.jpg"
#define SPLASH_STATE_SHOW_TIME 1


// Main Menu State
#define MAIN_MENU_STATE_BACKGROUND_FILEPATH "Resources/images/background.jpg"


// Play State
#define PLAY_STATE_BACKGROUND_FILEPATH "Resources/images/table.jpg"
#define PIECE_OFFSET 7.5
#define TIME_TO_DISPLAY_MESSAGE 5

enum class PlayStates {
	PLAYING,
	STALEMATE,
	INVALID,
	CHECKMATE,
	TRANSFORM
};

// Pieces
#define WHITE_PAWN_FILEPATH "Resources/images/white_pawn.png"
#define BLACK_PAWN_FILEPATH "Resources/images/black_pawn.png"
#define WHITE_KNIGHT_FILEPATH "Resources/images/white_knight.png"
#define BLACK_KNIGHT_FILEPATH "Resources/images/black_knight.png"
#define WHITE_BISHOP_FILEPATH "Resources/images/white_bishop.png"
#define BLACK_BISHOP_FILEPATH "Resources/images/black_bishop.png"
#define WHITE_ROOK_FILEPATH "Resources/images/white_rook.png"
#define BLACK_ROOK_FILEPATH "Resources/images/black_rook.png"
#define WHITE_QUEEN_FILEPATH "Resources/images/white_queen.png"
#define BLACK_QUEEN_FILEPATH "Resources/images/black_queen.png"
#define WHITE_KING_FILEPATH "Resources/images/white_king.png"
#define BLACK_KING_FILEPATH "Resources/images/black_king.png"
#define PLAY_BUTTON_FILEPATH "Resources/images/play-button.png"
#define PLAY_BUTTON_HOVER_FILEPATH "Resources/images/play-button-hover.png"

// Icon
#define ICON_FILEPATH "Resources/images/icon.png"

// Fonts
#define TIMES_NEW_ROMAN_FONT_FILEPATH "Resources/fonts/times-new-roman.ttf"

// Sounds
#define CAPTURE_SOUND_FILEPATH "Resources/sounds/capture.ogg"
#define CHECK_SOUND_FILEPATH "Resources/sounds/check.ogg"
#define INVALID_SOUND_FILEPATH "Resources/sounds/invalid.ogg"
#define LOSE_SOUND_FILEPATH "Resources/sounds/lose.ogg"
#define MOVE_SOUND_FILEPATH "Resources/sounds/move.ogg"
#define WIN_SOUND_FILEPATH "Resources/sounds/win.ogg"

typedef std::vector<int> PieceIds;
typedef std::vector<sf::Vector2i> Places;
typedef sf::Vector2i Position;
typedef int** Table;
typedef std::shared_ptr<sf::RenderWindow> WindowRef;

