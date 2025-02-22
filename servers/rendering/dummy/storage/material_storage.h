/*************************************************************************/
/*  material_storage.h                                                   */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef MATERIAL_STORAGE_DUMMY_H
#define MATERIAL_STORAGE_DUMMY_H

#include "servers/rendering/storage/material_storage.h"
#include "servers/rendering/storage/utilities.h"

namespace RendererDummy {

class MaterialStorage : public RendererMaterialStorage {
public:
	/* GLOBAL VARIABLE API */

	virtual void global_variable_add(const StringName &p_name, RS::GlobalVariableType p_type, const Variant &p_value) override {}
	virtual void global_variable_remove(const StringName &p_name) override {}
	virtual Vector<StringName> global_variable_get_list() const override { return Vector<StringName>(); }

	virtual void global_variable_set(const StringName &p_name, const Variant &p_value) override {}
	virtual void global_variable_set_override(const StringName &p_name, const Variant &p_value) override {}
	virtual Variant global_variable_get(const StringName &p_name) const override { return Variant(); }
	virtual RS::GlobalVariableType global_variable_get_type(const StringName &p_name) const override { return RS::GLOBAL_VAR_TYPE_MAX; }

	virtual void global_variables_load_settings(bool p_load_textures = true) override {}
	virtual void global_variables_clear() override {}

	virtual int32_t global_variables_instance_allocate(RID p_instance) override { return 0; }
	virtual void global_variables_instance_free(RID p_instance) override {}
	virtual void global_variables_instance_update(RID p_instance, int p_index, const Variant &p_value) override {}

	/* SHADER API */

	virtual RID shader_allocate() override { return RID(); }
	virtual void shader_initialize(RID p_rid) override {}
	virtual void shader_free(RID p_rid) override{};

	virtual void shader_set_code(RID p_shader, const String &p_code) override {}
	virtual void shader_set_path_hint(RID p_shader, const String &p_code) override {}

	virtual String shader_get_code(RID p_shader) const override { return ""; }
	virtual void shader_get_param_list(RID p_shader, List<PropertyInfo> *p_param_list) const override {}

	virtual void shader_set_default_texture_param(RID p_shader, const StringName &p_name, RID p_texture, int p_index) override {}
	virtual RID shader_get_default_texture_param(RID p_shader, const StringName &p_name, int p_index) const override { return RID(); }
	virtual Variant shader_get_param_default(RID p_material, const StringName &p_param) const override { return Variant(); }

	virtual RS::ShaderNativeSourceCode shader_get_native_source_code(RID p_shader) const override { return RS::ShaderNativeSourceCode(); };

	/* MATERIAL API */
	virtual RID material_allocate() override { return RID(); }
	virtual void material_initialize(RID p_rid) override {}
	virtual void material_free(RID p_rid) override{};

	virtual void material_set_render_priority(RID p_material, int priority) override {}
	virtual void material_set_shader(RID p_shader_material, RID p_shader) override {}

	virtual void material_set_param(RID p_material, const StringName &p_param, const Variant &p_value) override {}
	virtual Variant material_get_param(RID p_material, const StringName &p_param) const override { return Variant(); }

	virtual void material_set_next_pass(RID p_material, RID p_next_material) override {}

	virtual bool material_is_animated(RID p_material) override { return false; }
	virtual bool material_casts_shadows(RID p_material) override { return false; }
	virtual void material_get_instance_shader_parameters(RID p_material, List<InstanceShaderParam> *r_parameters) override {}
	virtual void material_update_dependency(RID p_material, DependencyTracker *p_instance) override {}
};

} // namespace RendererDummy

#endif // MATERIAL_STORAGE_DUMMY_H
