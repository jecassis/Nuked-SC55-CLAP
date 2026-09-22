#include <cassert>
#include <cstring>
#include <iterator>
#include <string>

#include "plugin.h"
#include "nuked_sc55.h"

//////////////////////////////////////////////////////////////////////////////
// Plugin descriptors
//////////////////////////////////////////////////////////////////////////////

// Number of plugins in this dynamic library
constexpr auto NumPlugins = 15;

constexpr auto Vendor  = PLUGIN_VENDOR;
constexpr auto Url     = PLUGIN_URL;
constexpr auto Version = PLUGIN_VERSION_STRING;

#define CLAP_PLUGIN_ID(suffix) "net.johnnovak.nuked_sc55_clap." suffix

const char *Features[] = {CLAP_PLUGIN_FEATURE_INSTRUMENT,
                          CLAP_PLUGIN_FEATURE_SYNTHESIZER,
                          CLAP_PLUGIN_FEATURE_STEREO,
                          nullptr};

static const clap_plugin_descriptor_t plugin_descriptor_sc55_v1_00 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("sc55_v1_00"),
    .name         = "Nuked SC-55 — Roland SC-55 v1.00",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = PLUGIN_DESCRIPTION_PREFIX " v1.00 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_sc55_v1_10 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("sc55_v1_10"),
    .name         = "Nuked SC-55 — Roland SC-55 v1.10",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = PLUGIN_DESCRIPTION_PREFIX " v1.10 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_sc55_v1_20 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("sc55_v1_20"),
    .name         = "Nuked SC-55 — Roland SC-55 v1.20",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = PLUGIN_DESCRIPTION_PREFIX " v1.20 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_sc55_v1_21 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("sc55_v1_21"),
    .name         = "Nuked SC-55 — Roland SC-55 v1.21",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = PLUGIN_DESCRIPTION_PREFIX " v1.21 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_sc55_v2_00 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("sc55_v2_00"),
    .name         = "Nuked SC-55 — Roland SC-55 v2.00",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = PLUGIN_DESCRIPTION_PREFIX " v2.00 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_sc55mk2_v1_01 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("sc55mk2_v1_01"),
    .name         = "Nuked SC-55 — Roland SC-55mk2 v1.01",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = PLUGIN_DESCRIPTION_PREFIX "mk2 v1.01 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_sc55st_v1_01 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("sc55st_v1_01"),
    .name         = "Nuked SC-55 — Roland SC-55st v1.01",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = PLUGIN_DESCRIPTION_PREFIX "st v1.01 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_sc155_rev1 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("sc155_rev1"),
    .name         = "Nuked SC-55 — Roland SC-155 rev 1",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = "Roland SC-155 rev 1 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_cm300_v1_10 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("cm300_v1_10"),
    .name         = "Nuked SC-55 — Roland CM-300/SCC-1 v1.10",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = "Roland CM-300/SCC-1 v1.10 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_cm300_v1_20 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("cm300_v1_20"),
    .name         = "Nuked SC-55 — Roland CM-300/SCC-1 v1.20",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = "Roland CM-300/SCC-1 v1.20 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_scc1a_v1_30 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("scc1a_v1_30"),
    .name         = "Nuked SC-55 — Roland SCC-1A v1.30",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = "Roland SCC-1A v1.30 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_scb55_v2_00 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("scb55_v2_00"),
    .name         = "Nuked SC-55 — Roland SCB-55 v2.00",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = "Roland SCB-55 v2.00 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_rlp3237_v2_01 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("rlp3237_v2_01"),
    .name         = "Nuked SC-55 — Roland RLP-3237 v2.01",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = "Roland RLP-3237 v2.01 " PLUGIN_DESCRIPTION_SUFFIX,
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_jv880_v1_00 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("jv880_v1_00"),
    .name         = "Nuked SC-55 — Roland JV-880 v1.00",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = "Roland JV-880 v1.00 MIDI synthesizer emulation",
    .features     = Features};

static const clap_plugin_descriptor_t plugin_descriptor_jv880_v1_01 = {
    .clap_version = CLAP_VERSION_INIT,
    .id           = CLAP_PLUGIN_ID("jv880_v1_01"),
    .name         = "Nuked SC-55 — Roland JV-880 v1.01",
    .vendor       = Vendor,
    .url          = Url,
    .manual_url   = Url,
    .support_url  = Url,
    .version      = Version,
    .description  = "Roland JV-880 v1.01 MIDI synthesizer emulation",
    .features     = Features};

//////////////////////////////////////////////////////////////////////////////
// Extensions
//////////////////////////////////////////////////////////////////////////////

static const clap_plugin_note_ports_t extension_note_ports = {
    .count = [](const clap_plugin_t* plugin, bool is_input) -> uint32_t {
        return is_input ? 1 : 0;
    },

    .get = [](const clap_plugin_t* plugin, uint32_t index, bool is_input,
              clap_note_port_info_t* info) -> bool {
        if (!is_input || index) {
            return false;
        }

        info->id = 0;

        // We don't support CLAP_NOTE_DIALECT_CLAP because we want to force
        // the sending of RAW MIDI messages at all times.
        info->supported_dialects = CLAP_NOTE_DIALECT_MIDI;
        info->preferred_dialect  = CLAP_NOTE_DIALECT_MIDI;

        snprintf(info->name, sizeof(info->name), "%s", "Note Port");

        return true;
    }};

static const clap_plugin_audio_ports_t extension_audio_ports = {
    .count = [](const clap_plugin_t* plugin, bool is_input) -> uint32_t {
        return is_input ? 0 : 1;
    },

    .get = [](const clap_plugin_t* plugin, uint32_t index, bool is_input,
              clap_audio_port_info_t* info) -> bool {
        if (is_input || index) {
            return false;
        }

        info->id            = 0;
        info->channel_count = 2; // stereo
        info->flags         = CLAP_AUDIO_PORT_IS_MAIN;
        info->port_type     = CLAP_PORT_STEREO;
        info->in_place_pair = CLAP_INVALID_ID;

        snprintf(info->name, sizeof(info->name), "%s", "Audio Output");

        return true;
    }};

static const clap_plugin_state_t extension_state = {
    .save = [](const clap_plugin_t* plugin, const clap_ostream_t* stream) -> bool {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        return the_plugin->SaveState(stream);
    },

    .load = [](const clap_plugin_t* plugin, const clap_istream_t* stream) -> bool {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        return the_plugin->LoadState(stream);
    }};

static const clap_plugin_params_t extension_params = {
    .count = [](const clap_plugin_t* plugin) -> uint32_t {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        return the_plugin->ParamsCount();
    },

    .get_info = [](const clap_plugin_t* plugin, uint32_t param_index,
                   clap_param_info_t* param_info) -> bool {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        return the_plugin->ParamsGetInfo(param_index, param_info);
    },

    .get_value = [](const clap_plugin_t* plugin, clap_id param_id,
                    double* out_value) -> bool {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        return the_plugin->ParamsGetValue(param_id, out_value);
    },

    .value_to_text = [](const clap_plugin_t* plugin, clap_id param_id, double value,
                        char* out_buffer, uint32_t out_buffer_capacity) -> bool {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        return the_plugin->ParamsValueToText(param_id, value, out_buffer, out_buffer_capacity);
    },

    .text_to_value = [](const clap_plugin_t* plugin, clap_id param_id,
                        const char* param_value_text, double* out_value) -> bool {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        return the_plugin->ParamsTextToValue(param_id, param_value_text, out_value);
    },

    .flush = [](const clap_plugin_t* plugin, const clap_input_events_t* in,
                const clap_output_events_t* out) {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        the_plugin->ParamsFlush(in, out);
    }};

//////////////////////////////////////////////////////////////////////////////
// Plugin classes
//////////////////////////////////////////////////////////////////////////////

static const void* get_extension(const clap_plugin* plugin, const char* id)
{
    if (strcmp(id, CLAP_EXT_NOTE_PORTS) == 0) {
        return &extension_note_ports;

    } else if (strcmp(id, CLAP_EXT_AUDIO_PORTS) == 0) {
        return &extension_audio_ports;

    } else if (strcmp(id, CLAP_EXT_STATE) == 0) {
        return &extension_state;

    } else if (strcmp(id, CLAP_EXT_PARAMS) == 0) {
        return &extension_params;

    } else {
        return nullptr;
    }
}

static clap_plugin_t make_plugin_class(const clap_plugin_descriptor_t* desc)
{
    clap_plugin_t plugin_class = {};

    plugin_class.desc        = desc;
    plugin_class.plugin_data = nullptr;

    plugin_class.init = [](const clap_plugin* plugin) -> bool {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        return the_plugin->Init(plugin);
    };

    plugin_class.destroy = [](const clap_plugin* plugin) {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        the_plugin->Shutdown();
        delete the_plugin;
    };

    plugin_class.activate = [](const clap_plugin* plugin, double sample_rate,
                               uint32_t min_frame_count, uint32_t max_frame_count) -> bool {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        return the_plugin->Activate(sample_rate, min_frame_count, max_frame_count);
    };

    plugin_class.deactivate = [](const clap_plugin* plugin) {};

    plugin_class.start_processing = [](const clap_plugin* plugin) -> bool { return true; };

    plugin_class.stop_processing = [](const clap_plugin* plugin) {};

    plugin_class.reset = [](const clap_plugin* plugin) {};

    plugin_class.process = [](const clap_plugin* plugin,
                              const clap_process_t* process) -> clap_process_status {
        auto the_plugin = (NukedSc55*)plugin->plugin_data;
        return the_plugin->Process(process);
    };

    plugin_class.get_extension = [](const clap_plugin* plugin, const char* id) -> const void* {
        return get_extension(plugin, id);
    };

    plugin_class.on_main_thread = [](const clap_plugin* plugin) {};

    return plugin_class;
}

//////////////////////////////////////////////////////////////////////////////
// Plugin factory
//////////////////////////////////////////////////////////////////////////////

struct PluginEntry {
    const clap_plugin_descriptor_t* desc;
    NukedSc55::Model model;
};

static const PluginEntry plugin_entries[] = {
    {&plugin_descriptor_sc55_v1_00, NukedSc55::Model::Sc55_v1_00},
    {&plugin_descriptor_sc55_v1_10, NukedSc55::Model::Sc55_v1_10},
    {&plugin_descriptor_sc55_v1_20, NukedSc55::Model::Sc55_v1_20},
    {&plugin_descriptor_sc55_v1_21, NukedSc55::Model::Sc55_v1_21},
    {&plugin_descriptor_sc55_v2_00, NukedSc55::Model::Sc55_v2_00},
    {&plugin_descriptor_sc55mk2_v1_01, NukedSc55::Model::Sc55mk2_v1_01},
    {&plugin_descriptor_sc55st_v1_01, NukedSc55::Model::Sc55st_v1_01},
    {&plugin_descriptor_sc155_rev1, NukedSc55::Model::Sc155_rev1},
    {&plugin_descriptor_cm300_v1_10, NukedSc55::Model::Cm300_v1_10},
    {&plugin_descriptor_cm300_v1_20, NukedSc55::Model::Cm300_v1_20},
    {&plugin_descriptor_scc1a_v1_30, NukedSc55::Model::Scc1a_v1_30},
    {&plugin_descriptor_scb55_v2_00, NukedSc55::Model::Scb55_v2_00},
    {&plugin_descriptor_rlp3237_v2_01, NukedSc55::Model::Rlp3237_v2_01},
    {&plugin_descriptor_jv880_v1_00, NukedSc55::Model::Jv880_v1_00},
    {&plugin_descriptor_jv880_v1_01, NukedSc55::Model::Jv880_v1_01},
};

static_assert(std::size(plugin_entries) == NumPlugins,
              "`NumPlugins` must match the `plugin_entries` table size");

static const clap_plugin_factory_t plugin_factory = {

    .get_plugin_count = [](const clap_plugin_factory* factory) -> uint32_t {
        return NumPlugins;
    },

    .get_plugin_descriptor = [](const clap_plugin_factory* factory,
                                uint32_t index) -> const clap_plugin_descriptor_t* {
        if (index >= std::size(plugin_entries)) {
            return nullptr;
        }
        return plugin_entries[index].desc;
    },

    .create_plugin = [](const clap_plugin_factory* factory, const clap_host_t* host,
                        const char* plugin_id) -> const clap_plugin_t* {
        if (!clap_version_is_compatible(host->clap_version)) {
            return nullptr;
        }

        for (const auto& entry : plugin_entries) {
            if (strcmp(plugin_id, entry.desc->id) == 0) {
                auto the_plugin = new NukedSc55(make_plugin_class(entry.desc),
                                                host, entry.model);
                return the_plugin->GetPluginClass();
            }
        }
        return nullptr;
    }};

//////////////////////////////////////////////////////////////////////////////
// Dynamic library definition
//////////////////////////////////////////////////////////////////////////////

std::string plugin_path = {};

extern "C" const clap_plugin_entry_t clap_entry = {
    .clap_version = CLAP_VERSION_INIT,

    .init = [](const char* _plugin_path) -> bool {
        plugin_path = std::string(_plugin_path);
        return true;
    },

    .deinit = []() {},

    .get_factory = [](const char* factory_id) -> const void* {
        return strcmp(factory_id, CLAP_PLUGIN_FACTORY_ID) ? nullptr : &plugin_factory;
    }};
