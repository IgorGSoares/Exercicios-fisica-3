#include "test.h"

class EX3_2 : public Test //você cria a sua classe derivada da classe base Test
{
public:
	EX3_2() {
		// Aqui no construtor você inicializa a cena


		b2Body* p1;
		b2Body* p2;

		p1 = CreateFloor(-10.0, 15.0, 0.5, 2);
		p2 = CreateFloor(5.5, 15.0, 0.5, 2);

		b2Body* b1;
		b1 = CreateBox(-7.5, 16.5, 2, 0.5, 1.0f, 0.3f, 0.0f);

		b2Vec2 worldAnchorOnBody1 = p1->GetWorldPoint(b2Vec2(0.5, 2.0));
		p1->SetType(b2_staticBody);
		b2RevoluteJointDef rJointDef;
		rJointDef.Initialize(p1, b1, worldAnchorOnBody1);
		
		b2RevoluteJoint* rjoint = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef);


		b2Body* b2;
		b2 = CreateBox(-4, 16.5, 2, 0.5, 1.0f, 0.3f, 0.0f);
		b2Vec2 worldAnchorOnBody2 = b1->GetWorldPoint(b2Vec2(2, 0.5));
		b2RevoluteJointDef rJointDef2;
		rJointDef2.Initialize(b1, b2, worldAnchorOnBody2);
		b2RevoluteJoint* rjoint2 = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef2);


		b2Body* b3;
		b3 = CreateBox(-0.5, 16.5, 2, 0.5, 1.0f, 0.3f, 0.0f);
		b2Vec2 worldAnchorOnBody3 = b2->GetWorldPoint(b2Vec2(2, 0.5));
		b2RevoluteJointDef rJointDef3;
		rJointDef3.Initialize(b2, b3, worldAnchorOnBody3);
		b2RevoluteJoint* rjoint3 = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef3);


		b2Body* b4;
		b4 = CreateBox(3, 16.5, 2, 0.5, 1.0f, 0.3f, 0.0f);
		b2Vec2 worldAnchorOnBody4 = b3->GetWorldPoint(b2Vec2(2, 0.5));
		b2RevoluteJointDef rJointDef4;
		rJointDef4.Initialize(b3, b4, worldAnchorOnBody4);
		b2RevoluteJoint* rjoint4 = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef4);


		b2Vec2 worldAnchorOnBody5 = p2->GetWorldPoint(b2Vec2(-0.5, 2.0));
		b2RevoluteJointDef rJointDef5;
		rJointDef5.Initialize(p2, b4, worldAnchorOnBody5);
		b2RevoluteJoint* rjoint5 = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef5);

	}

	void Step(Settings& settings) override
	{
		//Chama o passo da simulação e o algoritmo de rendering
		Test::Step(settings);

		//show some text in the main screen
		g_debugDraw.DrawString(5, m_textLine, "Pequena e simples ponte");
		m_textLine += 15;
	}

	static Test* Create()  //a classe Test que instancia um objeto da sua nova classe
						   //o autor da Box2D usa um padrão de projeto chamado Factory
						   //para sua arquitetura de classes
	{
		return new EX3_2;
	}

	b2Body* CreateBox(float x, float y, float width, float height,
		float density, float friction, float restitution)
	{
		// Define the dynamic body. We set its position and call the body factory.
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(x, y);
		b2Body* body = m_world->CreateBody(&bodyDef);

		// Define another box shape for our dynamic body.
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(width, height);

		// Define the dynamic body fixture.
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;

		// Set the box density to be non-zero, so it will be dynamic.
		fixtureDef.density = density;

		// Override the default friction.
		fixtureDef.friction = friction;

		//bounciness
		fixtureDef.restitution = restitution;

		// Add the shape to the body.
		body->CreateFixture(&fixtureDef);

		return body;
	}

	b2Body* CreateFloor(float x, float y, float width, float height)
	{
		// Define the ground body.
		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(x, y);

		// Call the body factory which allocates memory for the ground body
		// from a pool and creates the ground box shape (also from a pool).
		// The body is also added to the world.
		b2Body* groundBody = m_world->CreateBody(&groundBodyDef);

		// Define the ground box shape.
		b2PolygonShape groundBox;

		// The extents are the half-widths of the box.
		groundBox.SetAsBox(width, height);

		// Add the ground fixture to the ground body.
		groundBody->CreateFixture(&groundBox, 0.0f);

		return groundBody;
	}
};

//Aqui fazemos o registro do novo teste 
static int testIndex = RegisterTest("Examples", "EX3_2", EX3_2::Create);