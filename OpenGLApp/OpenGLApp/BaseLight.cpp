#include "BaseLight.h"

#include <ext/matrix_clip_space.hpp>

BaseLight::BaseLight(glm::vec4 InitColor,
					GLfloat InitAmbientIntensity,
					GLfloat InitDiffuseIntensity,
					GLint InitShadowWidth,
					GLint InitShadowHeight)
{
	Color = InitColor;
	AmbientIntensity = InitAmbientIntensity;
	DiffuseIntensity = InitDiffuseIntensity;

	ShadowMapTex = std::make_unique<ShadowMap>();
	ShadowMapTex->Init(InitShadowWidth, InitShadowHeight);

	LightProjectionMatrix = glm::ortho(5.0f, 5.0f, 5.0f, 5.0f, 0.1f, 30.0f);
}
