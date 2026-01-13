#include "Button.h"

void Button::isPressed(float mouseX, float mouseY, bool mousePress)
{
	if (mouseX >= m_rect.x && mouseX <= m_rect.x + m_rect.w
		&& mouseY >= m_rect.y && mouseY <= m_rect.y + m_rect.h
		&& mousePress)
	{
		std::cout << "boutton clicked\n";
	}
	

}

void Button::Draw()
{


}