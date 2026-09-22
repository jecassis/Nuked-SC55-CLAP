#pragma once

#include <array>
#include <atomic>
#include <filesystem>
#include <memory>
#include <vector>

#include "clap/clap.h"
#include "nuked-sc55/backend/emu.h"
#include "speex/speex_resampler.h"

class NukedSc55 {
public:
    enum class Model {
        Sc55_v1_00,
        Sc55_v1_10,
        Sc55_v1_20,
        Sc55_v1_21,
        Sc55_v2_00,
        Sc55mk2_v1_01,
        Sc55st_v1_01,
        Sc155_rev1,
        Cm300_v1_10,
        Cm300_v1_20,
        Scc1a_v1_30,
        Scb55_v2_00,
        Rlp3237_v2_01,
        Jv880_v1_00,
        Jv880_v1_01
    };

    // Init/shutdown
    NukedSc55(const clap_plugin_t plugin_class, const clap_host_t* host,
              const Model model);

    const clap_plugin_t* GetPluginClass();

    bool Init(const clap_plugin* plugin_instance);
    void Shutdown();

    bool Activate(const double sample_rate, const uint32_t min_frame_count,
                  const uint32_t max_frame_count);

    // Processing
    clap_process_status Process(const clap_process_t* process);

    void Flush(const clap_input_events_t* in, const clap_output_events_t* out);

    void PublishFrame(const float left, const float right);

    // State handling
    bool LoadState(const clap_istream_t* stream);
    bool SaveState(const clap_ostream_t* stream);

    // Parameters
    uint32_t ParamsCount() const;
    bool ParamsGetInfo(const uint32_t param_index, clap_param_info_t* info) const;
    bool ParamsGetValue(const clap_id param_id, double* out_value) const;
    bool ParamsValueToText(const clap_id param_id, const double value,
                           char* out_buffer, const uint32_t out_buffer_capacity) const;
    bool ParamsTextToValue(const clap_id param_id, const char* param_value_text,
                           double* out_value) const;
    void ParamsFlush(const clap_input_events_t* in, const clap_output_events_t* out);

private:
    std::filesystem::path path = {};

    std::filesystem::path nvram_path = {};

    Model model = {};

    clap_plugin_t plugin_class         = {};
    const clap_host_t* host            = nullptr;
    const clap_plugin* plugin_instance = nullptr;

    std::unique_ptr<Emulator> emu = nullptr;

    double render_sample_rate_hz = 0.0;
    double output_sample_rate_hz = 0.0;

    std::array<std::vector<float>, 2> render_buf = {};

    SpeexResamplerState* resampler = nullptr;
    bool do_resample               = false;
    double resample_ratio          = 0.0f;

    std::atomic<bool> remove_dc_offset = true;

    std::atomic<float> output_gain = 1.0f;

    // Methods
    std::vector<std::filesystem::path> GetRomEnvDirs();
    std::vector<std::filesystem::path> GetRomBasePaths();

    void LoadJv880Nvram(const std::filesystem::path& rom_dir);
    void SaveJv880Nvram();

    void ProcessEvent(const clap_event_header_t* event);

    void RenderAudio(const uint32_t num_frames);

    void ResampleAndPublishFrames(const uint32_t num_out_frames,
                                  float* out_left, float* out_right);
};
