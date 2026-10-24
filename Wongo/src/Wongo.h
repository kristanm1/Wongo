#ifndef _WONGO_
#define _WONGO_

// For use by Wongo applications

#include "Wongo/Core.h"
#include "Wongo/Application.h"
#include "Wongo/Logger.h"
#include "Wongo/Window.h"

#include "Wongo/Events/WindowEvent.h"

#include "Wongo/Renderer/Backend.h"
#include "Wongo/Renderer/Buffer.h"
#include "Wongo/Renderer/VertexArray.h"
#include "Wongo/Renderer/Shader.h"
#include "Wongo/Renderer/Program.h"
#include "Wongo/Renderer/Texture.h"

#include "imgui.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#endif

#ifdef WONGO_ENTRY_POINT // todo: dont like it..
#include "Wongo/EntryPoint.h"
#endif
