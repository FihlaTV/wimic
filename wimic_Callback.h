/*
   WiMic remote wireless microphone server/client.
   Copyright (c) 2020 Hiroshi Takey F. <htakey@gmail.com>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


# pragma once

#include "RingBuffer.hpp"
#include <speex/speex_echo.h>

#include <inttypes.h>
#include <string>
#include <stdio.h>
#include <memory>
#include <thread>
#include <unistd.h>

#define MAX_SESSION               10    // Client sessions.
#define MAX_PCM_INTERNAL_BUF    5000    // Auxliar internal frame buffers.
#ifndef PCM_FRAME
#define PCM_FRAME                640    // Frame for incomming PCM buffer stream from decoded opus data.
#endif

class wimic_Callback;

namespace WIMIC {
    const wimic_Callback &get_instance();
}

class wimic_Callback
{
public:
    wimic_Callback();
    ~wimic_Callback(void);

    void init(std::shared_ptr<RingBuffer<int16_t>> out_buf);
    void update_audio(int target,
                      int sessionId,
                      int sequenceNumber,
                      int16_t *pcm_data,
                      uint32_t pcm_data_size);

    static wimic_Callback *get_instance()
    {
        return _instance;
    }

    void stop();

private:

    static wimic_Callback *_instance;
    static bool _initialized;

    static bool _started;
    static uint16_t _chan_speak_cnt;

    static std::shared_ptr<RingBuffer<int16_t>> _out_buf;
    static std::shared_ptr<RingBuffer<int16_t>> _out_buf_tmp[MAX_SESSION];

    static int16_t _pcmbuf_out[MAX_PCM_INTERNAL_BUF];
    static int16_t _pcmbuf_in[MAX_PCM_INTERNAL_BUF];

    static void *_timer_buf(void *arg);
    static int16_t mix_pcm(int16_t pcm_one, int16_t pcm_two);
    static void _resampler(uint16_t inputSr, uint16_t outputSr, uint16_t channels, uint16_t frames, int16_t* data, uint16_t &out_length, int16_t* out_data);
    static void _resampler_float(uint16_t inputSr, uint16_t outputSr, uint16_t channels, uint16_t frames, int16_t* in_data, uint16_t &out_length, int16_t* out_data, bool resample_float = false);
    static void _update_echo_canceller(int16_t *in_out_datatmp, int16_t *out_data, int16_t *echo, uint16_t outputSr, uint16_t output_frames);
};
