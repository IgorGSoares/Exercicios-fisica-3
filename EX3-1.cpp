#include "test.h"

class EX3_1 : public Test //você cria a sua classe derivada da classe base Test
{
public:
	EX3_1() {
		// Aqui no construtor você inicializa a cena

		b2WheelJoint* m_joint;
		float m_motorSpeed;
		bool m_enableMotor;
		bool m_enableLimit;


		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = m_world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.SetTwoSided(b2Vec2(-40.0f, -2.0f), b2Vec2(40.0f, -2.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		m_enableLimit = true;
		m_enableMotor = true;
		m_motorSpeed = 10.0f;

		b2Body* body;
		{
			b2CircleShape shape;
			shape.m_radius = 2.0f;

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0.0f, 20.0f);
			bd.allowSleep = false;
			body = m_world->CreateBody(&bd);
			body->CreateFixture(&shape, 5.0f);	
		}

		/*b2Body* body;
		body = CreateBox(0.0f, 20.0f, 2, 0.5, 1.0f, 0.3f, 0.0f);*/


		b2WheelJointDef jd;

		// Horizontal
		jd.Initialize(ground, body, body->GetPosition(), b2Vec2(1.0f, 0.0f));

		jd.motorSpeed = m_motorSpeed;
		jd.maxMotorTorque = 10000.0f;
		jd.enableMotor = m_enableMotor;
		jd.lowerTranslation = -3.0f;
		jd.upperTranslation = 3.0f;
		jd.enableLimit = m_enableLimit;

		float hertz = 1.0f;
		float dampingRatio = 0.7f;
		b2LinearStiffness(jd.stiffness, jd.damping, hertz, dampingRatio, ground, body);

		m_joint = (b2WheelJoint*)m_world->CreateJoint(&jd);

		b2Body* b1;
		b1 = CreateBox(0.0f, 15.5f, 1, 3, 1.0f, 0.3f, 0.0f);

		b2Vec2 worldAnchorOnBody1 = body->GetWorldPoint(b2Vec2(0, -2.0));
		b2RevoluteJointDef rJointDef;
		rJointDef.Initialize(body, b1, worldAnchorOnBody1);
		rJointDef.collideConnected = true;
		b2RevoluteJoint* rjoint = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef);
		


		b2Body* b2;
		b2 = CreateBox(0.0f, 24.5f, 1, 3, 1.0f, 0.3f, 0.0f);
		b2Vec2 worldAnchorOnBody2 = body->GetWorldPoint(b2Vec2(0, 2.0));
		b2RevoluteJointDef rJointDef2;
		rJointDef2.Initialize(body, b2, worldAnchorOnBody2);
		rJointDef2.collideConnected = true;
		b2RevoluteJoint* rjoint2 = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef2);



		b2Body* b3;
		b3 = CreateBox(-4.5f, 20, 3, 1, 1.0f, 0.3f, 0.0f);
		b2Vec2 worldAnchorOnBody3 = body->GetWorldPoint(b2Vec2(-2, 0));
		b2RevoluteJointDef rJointDef3;
		rJointDef3.Initialize(body, b3, worldAnchorOnBody3);
		rJointDef3.collideConnected = true;
		b2RevoluteJoint* rjoint3 = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef3);


		b2Body* b4;
		b4 = CreateBox(4.5f, 20, 3, 1, 1.0f, 0.3f, 0.0f);
		b2Vec2 worldAnchorOnBody4 = body->GetWorldPoint(b2Vec2(2, 0));
		b2RevoluteJointDef rJointDef4;
		rJointDef4.Initialize(body, b4, worldAnchorOnBody4);
		rJointDef4.collideConnected = true;
		b2RevoluteJoint* rjoint4 = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef4);



		b2Body* b5;
		b5 = CreateBox(0, 10, 0.5, 0.5, 1.0f, 0.3f, 0.0f);
		b2Vec2 worldAnchorOnBody5 = b1->GetWorldPoint(b2Vec2(0, -2));
		b2Vec2 worldAnchorOnBody6 = b5->GetWorldCenter();
		b2DistanceJointDef dJointDef5;
		dJointDef5.Initialize(b1, b5, worldAnchorOnBody5, worldAnchorOnBody6);
		dJointDef5.collideConnected = true;
		b2DistanceJoint* dJoint5 = (b2DistanceJoint*)m_world->CreateJoint(&dJointDef5);


		b2Body* b6;
		b6 = CreateBox(10, 20, 0.5, 0.5, 1.0f, 0.3f, 0.0f);
		b2Vec2 worldAnchorOnBody7 = b4->GetWorldPoint(b2Vec2(2, 0));
		b2Vec2 worldAnchorOnBody8 = b6->GetWorldCenter();
		b2DistanceJointDef dJointDef6;
		dJointDef6.Initialize(b4, b6, worldAnchorOnBody7, worldAnchorOnBody8);
		dJointDef6.collideConnected = true;
		b2DistanceJoint* dJoint6 = (b2DistanceJoint*)m_world->CreateJoint(&dJointDef6);



		b2Body* b7;
		b7 = CreateBox(-10, 20, 0.5, 0.5, 1.0f, 0.3f, 0.0f);
		b2Vec2 worldAnchorOnBody9 = b3->GetWorldPoint(b2Vec2(-2, 0));
		b2Vec2 worldAnchorOnBody10 = b7->GetWorldCenter();
		b2DistanceJointDef dJointDef7;
		dJointDef7.Initialize(b3, b7, worldAnchorOnBody9, worldAnchorOnBody10);
		dJointDef7.collideConnected = true;
		b2DistanceJoint* dJoint7 = (b2DistanceJoint*)m_world->CreateJoint(&dJointDef7);



		b2Body* b8;
		b8 = CreateBox(0, 30, 0.5, 0.5, 1.0f, 0.3f, 0.0f);
		b2Vec2 worldAnchorOnBody11 = b2->GetWorldPoint(b2Vec2(0, 2));
		b2Vec2 worldAnchorOnBody12 = b8->GetWorldCenter();
		b2DistanceJointDef dJointDef8;
		dJointDef8.Initialize(b2, b8, worldAnchorOnBody11, worldAnchorOnBody12);
		dJointDef8.collideConnected = true;
		b2DistanceJoint* dJoint8 = (b2DistanceJoint*)m_world->CreateJoint(&dJointDef8);
		
	}

	void Step(Settings& settings) override
	{
		//Chama o passo da simulação e o algoritmo de rendering
		Test::Step(settings);

		//show some text in the main screen
		g_debugDraw.DrawString(5, m_textLine, "Este motor eh um variante do exercicio 1");
		m_textLine += 15;
	}

	static Test* Create()  //a classe Test que instancia um objeto da sua nova classe
						   //o autor da Box2D usa um padrão de projeto chamado Factory
						   //para sua arquitetura de classes
	{
		return new EX3_1;
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
static int testIndex = RegisterTest("Examples", "EX3_1", EX3_1::Create);