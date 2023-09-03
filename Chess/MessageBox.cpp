#include "MessageBox.h"
#include "WindowManager.h"
#include "AssetManager.h"

void MessageBox::Init(const sf::FloatRect& rect, float radius, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineWidth) {
	// Draw circles 	
	this->SetCircles(rect, radius, fillColor, outlineColor, outlineWidth);

	// Draw outlines
	this->SetOutlines(rect, radius, outlineColor, outlineWidth);

	// Init Box
	this->InitBox(rect, radius, fillColor);
}

void MessageBox::InitBox(const sf::FloatRect& rect, float radius, const sf::Color& fillColor) {
	this->box.setPointCount(12);

	// Extract coordinates
	float x = rect.left, y = rect.top, width = rect.width, height = rect.height;

	// Set up points
	this->box.setPoint(0, sf::Vector2f(x, y + radius));
	this->box.setPoint(1, sf::Vector2f(x + radius, y + radius));
	this->box.setPoint(2, sf::Vector2f(x + radius, y));
	this->box.setPoint(3, sf::Vector2f(x + width - radius, y));
	this->box.setPoint(4, sf::Vector2f(x + width - radius, y + radius));
	this->box.setPoint(5, sf::Vector2f(x + width, y + radius));
	this->box.setPoint(6, sf::Vector2f(x + width, y + height - radius));
	this->box.setPoint(7, sf::Vector2f(x + width - radius, y + height - radius));
	this->box.setPoint(8, sf::Vector2f(x + width - radius, y + height));
	this->box.setPoint(9, sf::Vector2f(x + radius, y + height));
	this->box.setPoint(10, sf::Vector2f(x + radius, y + height - radius));
	this->box.setPoint(11, sf::Vector2f(x, y + height - radius));
	this->box.setFillColor(fillColor);
}

void MessageBox::SetCircles(const sf::FloatRect& rect, float radius, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineWidth) { 
	for(int i = 0; i < 4; i++) {
		this->edges[i].setRadius(radius);
		this->edges[i].setOrigin(radius, radius);
		this->edges[i].setFillColor(fillColor);
		this->edges[i].setOutlineThickness(outlineWidth);
		this->edges[i].setOutlineColor(outlineColor);
		switch (i) {
			case 0:
				this->edges[i].setPosition(rect.left + radius, rect.top + radius);
				break;
			case 1:
				this->edges[i].setPosition(rect.left + rect.width - radius, rect.top + radius);
				break;
			case 2:
				this->edges[i].setPosition(rect.left + rect.width - radius, rect.top + rect.height - radius);
				break;
			case 3:
				this->edges[i].setPosition(rect.left + radius, rect.top + rect.height - radius);
				break;
			default:
				break;
		}
	}
}

void MessageBox::SetOutlines(const sf::FloatRect& rect, float radius, const sf::Color& outlineColor, float outlineWidth) {
	for (int i = 0; i < 4; i++) {
		this->outlines[i].setFillColor(outlineColor);
		switch (i) {
		case 0:
			this->outlines[i].setPosition(rect.left - (float)outlineWidth, rect.top + radius);
			this->outlines[i].setSize(sf::Vector2f((float)outlineWidth, rect.height - 2 * radius));
			break;
		case 1:
			this->outlines[i].setPosition(rect.left + radius, rect.top - (float)outlineWidth);
			this->outlines[i].setSize(sf::Vector2f(rect.width - 2 * radius, (float)outlineWidth));
			break;
		case 2:
			this->outlines[i].setPosition(rect.left + rect.width, rect.top + radius);
			this->outlines[i].setSize(sf::Vector2f((float)outlineWidth, rect.height - 2 * radius));
			break;
		case 3:
			this->outlines[i].setPosition(sf::Vector2f(rect.left + radius, rect.top + rect.height));
			this->outlines[i].setSize(sf::Vector2f(rect.width - 2 * radius, (float)outlineWidth));
			break;
		default:
			break;
		}
	}
}

void MessageBox::SetText(const std::string& text, const sf::Color& color, unsigned int size) {
	this->message.setFont(assetManager->GetFont("Times New Roman"));
	this->message.setStyle(sf::Text::Bold);
	this->message.setFillColor(color);
	this->message.setString(text);
	this->message.setCharacterSize(size);
	this->message.setOrigin(this->message.getLocalBounds().width / 2.f, this->message.getLocalBounds().height / 2.f);
}

void MessageBox::SetTextPosition(const sf::Vector2f& position) {
	this->message.setPosition(position);
}

void MessageBox::Display() {
	for (int i = 0; i < 4; i++) {
		window->draw(this->edges[i]);
		window->draw(this->outlines[i]);
	}
	window->draw(this->box);
	window->draw(this->message);
}