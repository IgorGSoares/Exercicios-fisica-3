#include "test.h"

class peixe : public Test //voc� cria a sua classe derivada da classe base Test
{
public:

	b2Vec2 force;
	b2Vec2 ptG;

	b2Body* body;

	b2Body* fish1;


	peixe() {
		// Aqui no construtor voc� inicializa a cena

		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = m_world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.SetTwoSided(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		b2PrismaticJoint* m_joint;
		float m_motorSpeed;
		bool m_enableMotor;
		bool m_enableLimit;

		m_enableLimit = true;
		m_enableMotor = false;
		m_motorSpeed = 10.0f;


		
		b2PolygonShape shape;
		shape.SetAsBox(1.0f, 1.0f);
		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position.Set(0.0f, 40.0f);
		bd.angle = 0.5f * b2_pi;
		bd.allowSleep = false;
		body = m_world->CreateBody(&bd);
		body->CreateFixture(&shape, 5.0f);
		

		// Horizontal
		b2PrismaticJointDef pjd;
		pjd.Initialize(ground, body, bd.position, b2Vec2(0.0f, 1.0f));
		pjd.motorSpeed = m_motorSpeed;
		pjd.maxMotorForce = 10000.0f;
		pjd.enableMotor = m_enableMotor;
		pjd.lowerTranslation = -1.0f;
		pjd.upperTranslation = 1.0f;
		pjd.enableLimit = m_enableLimit;

		m_joint = (b2PrismaticJoint*)m_world->CreateJoint(&pjd);


		//Primeiro, criamos a defini��o do corpo
		b2BodyDef bodyDef;
		bodyDef.position.Set(0.0, 20.0f);
		bodyDef.type = b2_dynamicBody;
		b2PolygonShape* formas = new b2PolygonShape;
		b2FixtureDef* partes = new b2FixtureDef;

		//head
		b2Vec2* head = new b2Vec2[5];
		head[0] = b2Vec2(0 * 1, 7 * 1);
		head[1] = b2Vec2(-3 * 1, 5 * 1);
		head[2] = b2Vec2(-3 * 1, 2 * 1);
		head[3] = b2Vec2(3 * 1, 2 * 1);
		head[4] = b2Vec2(3 * 1, 5 * 1);
		formas[0].Set(head, 5);
		//Depois, criamos uma fixture que vai conter a forma do corpo
		partes->shape = formas;
		//Setamos outras propriedades da fixture
		partes->density = 10.0;
		partes->friction = 0.5;
		partes->restitution = 0.5;

		fish1 = m_world->CreateBody(&bodyDef);
		//... e criamos a fixture do corpo  
		fish1->CreateFixture(partes);


		b2Vec2 worldAnchorOnBody1 = body->GetWorldCenter();
		b2Vec2 worldAnchorOnBody2 = fish1->GetWorldCenter();
		b2DistanceJointDef dJointDef;
		dJointDef.Initialize(body, fish1, worldAnchorOnBody1, worldAnchorOnBody2);
		dJointDef.collideConnected = true;
		b2DistanceJoint* dJoint = (b2DistanceJoint*)m_world->CreateJoint(&dJointDef);


		b2Body* fish2;
		{
			//Primeiro, criamos a defini��o do corpo
			b2BodyDef bodyDef;
			bodyDef.position.Set(0.0, 19.0f);
			bodyDef.type = b2_dynamicBody;
			b2PolygonShape* formas = new b2PolygonShape;
			b2FixtureDef* partes = new b2FixtureDef;

			//head
			b2Vec2* head = new b2Vec2[4];
			head[0] = b2Vec2(-3 * 1, 2 * 1);
			head[1] = b2Vec2(-2 * 1, 0 * 1);
			head[2] = b2Vec2(2 * 1, 0 * 1);
			head[3] = b2Vec2(3 * 1, 2 * 1);
			formas[0].Set(head, 4);
			//Depois, criamos uma fixture que vai conter a forma do corpo
			partes->shape = formas;
			//Setamos outras propriedades da fixture
			partes->density = 10.0;
			partes->friction = 0.5;
			partes->restitution = 0.5;

			fish2 = m_world->CreateBody(&bodyDef);
			//... e criamos a fixture do corpo  
			fish2->CreateFixture(partes);
		}

		b2Vec2 worldAnchorOnBody3 = fish1->GetWorldPoint(b2Vec2(0, 2));
		b2RevoluteJointDef rJointDef;
		rJointDef.Initialize(fish1, fish2, worldAnchorOnBody3);
		rJointDef.collideConnected = true;
		b2RevoluteJoint* rjoint = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef);



		b2Body* fish3;
		{
			//Primeiro, criamos a defini��o do corpo
			b2BodyDef bodyDef;
			bodyDef.position.Set(0.0, 18.0f);
			bodyDef.type = b2_dynamicBody;
			b2PolygonShape* formas = new b2PolygonShape;
			b2FixtureDef* partes = new b2FixtureDef;

			//head
			b2Vec2* head = new b2Vec2[4];
			head[0] = b2Vec2(-2 * 1, 0 * 1);
			head[1] = b2Vec2(-1 * 1, -2 * 1);
			head[2] = b2Vec2(1 * 1, -2 * 1);
			head[3] = b2Vec2(2 * 1, 0 * 1);
			formas[0].Set(head, 4);
			//Depois, criamos uma fixture que vai conter a forma do corpo
			partes->shape = formas;
			//Setamos outras propriedades da fixture
			partes->density = 10.0;
			partes->friction = 0.5;
			partes->restitution = 0.5;

			fish3 = m_world->CreateBody(&bodyDef);
			//... e criamos a fixture do corpo  
			fish3->CreateFixture(partes);
		}

		b2Vec2 worldAnchorOnBody4 = fish2->GetWorldPoint(b2Vec2(0, 0));
		b2RevoluteJointDef rJointDef2;
		rJointDef2.Initialize(fish2, fish3, worldAnchorOnBody4);
		rJointDef2.collideConnected = true;
		b2RevoluteJoint* rjoint2 = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef2);



		b2Body* fish4;
		{
			//Primeiro, criamos a defini��o do corpo
			b2BodyDef bodyDef;
			bodyDef.position.Set(0.0, 17.5f);
			bodyDef.type = b2_dynamicBody;
			b2PolygonShape* formas = new b2PolygonShape;
			b2FixtureDef* partes = new b2FixtureDef;

			//head
			b2Vec2* head = new b2Vec2[4];
			head[0] = b2Vec2(-1 * 1, -2 * 1);
			head[1] = b2Vec2(-1 * 1, -3 * 1);
			head[2] = b2Vec2(1 * 1, -3 * 1);
			head[3] = b2Vec2(1 * 1, -2 * 1);
			formas[0].Set(head, 4);
			//Depois, criamos uma fixture que vai conter a forma do corpo
			partes->shape = formas;
			//Setamos outras propriedades da fixture
			partes->density = 10.0;
			partes->friction = 0.5;
			partes->restitution = 0.5;

			fish4 = m_world->CreateBody(&bodyDef);
			//... e criamos a fixture do corpo  
			fish4->CreateFixture(partes);
		}

		b2Vec2 worldAnchorOnBody5 = fish3->GetWorldPoint(b2Vec2(0, -2));
		b2RevoluteJointDef rJointDef3;
		rJointDef3.Initialize(fish3, fish4, worldAnchorOnBody5);
		rJointDef3.collideConnected = true;
		b2RevoluteJoint* rjoint3 = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef3);


		b2Body* fish5;
		{
			//Primeiro, criamos a defini��o do corpo
			b2BodyDef bodyDef;
			bodyDef.position.Set(0.0, 15.0f);
			bodyDef.type = b2_dynamicBody;
			b2PolygonShape* formas = new b2PolygonShape;
			b2FixtureDef* partes = new b2FixtureDef;

			//head
			b2Vec2* head = new b2Vec2[4];
			head[0] = b2Vec2(-3 * 1, -2 * 1);
			head[1] = b2Vec2(-1 * 1, -1 * 1);
			head[2] = b2Vec2(1 * 1, -1 * 1);
			head[3] = b2Vec2(3 * 1, -2 * 1);

			formas[0].Set(head, 4);
			//Depois, criamos uma fixture que vai conter a forma do corpo
			partes->shape = formas;
			//Setamos outras propriedades da fixture
			partes->density = 10.0;
			partes->friction = 0.5;
			partes->restitution = 0.5;

			fish5 = m_world->CreateBody(&bodyDef);
			//... e criamos a fixture do corpo  
			fish5->CreateFixture(partes);
		}

		b2Vec2 worldAnchorOnBody6 = fish4->GetWorldPoint(b2Vec2(0, -3));
		b2RevoluteJointDef rJointDef4;
		rJointDef4.Initialize(fish4, fish5, worldAnchorOnBody6);
		rJointDef4.collideConnected = true;
		b2RevoluteJoint* rjoint4 = (b2RevoluteJoint*)m_world->CreateJoint(&rJointDef4);

	}

	void Step(Settings& settings) override
	{
		//Chama o passo da simula��o e o algoritmo de rendering
		Test::Step(settings);

		//show some text in the main screen
		g_debugDraw.DrawString(5, m_textLine, "Use as teclas A e D para mover o peixe. Ele eh um variante do ex 1");
		m_textLine += 15;
	}

	static Test* Create()  //a classe Test que instancia um objeto da sua nova classe
						   //o autor da Box2D usa um padr�o de projeto chamado Factory
						   //para sua arquitetura de classes
	{
		return new peixe;
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



	void Keyboard(int key) override
	{
		switch (key)
		{
		case GLFW_KEY_A:
			//force = b2Vec2(-2000.0, 0.0);
			force = b2Vec2(-3000.0, 0.0);
			/*ptG = b1->GetWorldPoint(b2Vec2(-0.5f, 2.0f));
			b1->ApplyForce(force, ptG, true);*/
			fish1->ApplyForceToCenter(force, true);
			fish1->ApplyLinearImpulse(force, fish1->GetWorldCenter(), true);
			break;

		case GLFW_KEY_D:
			//force = b2Vec2(2000.0, 0.0);
			force = b2Vec2(3000.0, 0.0);
			/*ptG = b1->GetWorldPoint(b2Vec2(-0.5f, 2.0f));
			b1->ApplyForce(force, ptG, true);*/
			fish1->ApplyForceToCenter(force, true);
			fish1->ApplyLinearImpulse(force, fish1->GetWorldCenter(), true);
			break;
		}
	}


	b2Vec2 decomposeVector(float a, float m)
	{
		b2Vec2 dec;
		dec.x = m * cos(degToRadian(a));
		dec.y = m * sin(degToRadian(a));
		return dec;
	}

	float degToRadian(float a)
	{
		return a * b2_pi / 180.0f;
	}

};

//Aqui fazemos o registro do novo teste 
static int testIndex = RegisterTest("Examples", "peixe", peixe::Create);