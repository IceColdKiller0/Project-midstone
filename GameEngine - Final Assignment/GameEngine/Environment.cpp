#include "Environment.h"

Environment::Environment() {
	pullCircles = nullptr;
	initCircles(7);
}

Environment::~Environment() {
	delete pullCircles;
}

void Environment::initCircles(size_t size) {
	for (size_t i = 0; i < size; ++i) {

		float x = (float)(rand() % 1000);
		float y = (float)(rand() % 600);
		float radius = 40; //(float)(15 + (rand() % (40 - 16)));

		Circle circle = Circle(radius);
		circle.Position(x, y);

		circles.push_back(circle);
	}
}

void Environment::update(float deltatime) {

	CircleCollision();

	for (Circle& circle : circles) {
		circle.update(deltatime);
	}
}

void Environment::CircleCollision() {

	for (Circle& circle : circles) {
		for (Circle& circle2 : circles) {

			if (&circle != &circle2) {
				if (collision.circleOverlap(circle, circle2)) {

					float distance = collision.distanceSquared(circle.getPos(), circle2.getPos());
					float distanceSquared = sqrtf(distance);
					float overlap = (distanceSquared - circle.getR() - circle2.getR()) / 2.f;

					float moveX = (overlap * (circle.getPos().x - circle2.getPos().x) / distanceSquared);
					float moveY = (overlap * (circle.getPos().y - circle2.getPos().y) / distanceSquared);

					circle.Position(circle.getPos().x - moveX, circle.getPos().y - moveY);
					circle2.Position(circle2.getPos().x + moveX, circle2.getPos().y + moveY);

					sf::Vector2f normal((circle2.getPos().x - circle.getPos().x) / distanceSquared, (circle2.getPos().y - circle.getPos().y) / distanceSquared);
					sf::Vector2f tangent(-normal.y, normal.x);

					float dotProductTangent1 = circle.getVel().x * tangent.x + circle.getVel().y * tangent.y;
					float dotProductTangent2 = circle2.getVel().x * tangent.x + circle2.getVel().y * tangent.y;

					float dotProductNormal1 = circle.getVel().x * normal.x + circle.getVel().y * normal.y;
					float dotProductNormal2 = circle2.getVel().x * normal.x + circle2.getVel().y * normal.y;

					float m1 = (dotProductNormal1 * (circle.getMass() - circle2.getMass()) + 2.0f * circle.getMass() * dotProductNormal2) / (circle.getMass() + circle2.getMass());
					float m2 = (dotProductNormal2 * (circle2.getMass() - circle.getMass()) + 2.0f * circle.getMass() * dotProductNormal1) / (circle.getMass() + circle2.getMass());

					circle.Velocity(tangent.x * dotProductTangent1 + normal.x * m1, tangent.y * dotProductTangent1 + normal.y * m1);
					circle2.Velocity(tangent.x * dotProductTangent2 + normal.x * m2, tangent.y * dotProductTangent2 + normal.y * m2);
				}
			}
		}
	}
}

bool Environment::_pullCircle(sf::Vector2f point) {

	for (Circle& circle : circles) {
		if (collision.circlePointOverlap(sf::Vector2f(point.x, point.y), circle)) {
			pullCircles = &circle;
			return true;
		}
	}
	return false;
}

void Environment::setPullVel(float x, float y) {

	if (pullCircles) {
		pullCircles->Velocity((pullCircles->getPos().x - x) / 100,
			(pullCircles->getPos().y - y) / 100);

		pullCircles = nullptr;
	}
}

Circle* Environment::getPullCircle() const {
	return pullCircles;
}

std::vector<Circle> Environment::getCircles() const {
	return circles;
}