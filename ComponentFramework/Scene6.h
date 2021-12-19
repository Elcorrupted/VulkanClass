#ifndef SCENE6_H
#define SCENE6_H
#include "Scene.h"
union SDL_Event;
class Scene6 : public Scene {
public:
	explicit Scene6();
	virtual ~Scene6();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void HandleEvents(const SDL_Event &sdlEvent) override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
};


#endif // SCENE6_H