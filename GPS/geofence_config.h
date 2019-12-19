/**
 ******************************************************************************
 * @file    GPSGeofence.h
 * @author  AST/CL
 * @version V1.1.0
 * @date    Oct, 2017
 * @brief   .
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

#ifndef __GPS_GEOFENCE_CFG_DATA_H__
#define __GPS_GEOFENCE_CFG_DATA_H__

typedef enum GeofenceId {
  LecceId,
  CataniaId
} eGeofenceId;
/*
GPSGeofence::GeofenceCircle_t STLecce = {
    .id = 5,
    .enabled = 1,
    .tolerance = 1,
    .lat = 40.336055,
    .lon = 18.120611,
    .radius = 200
  };
  
GPSGeofence::GeofenceCircle_t Catania = {
    .id = 6,
    .enabled = 1,
    .tolerance = 1,
    .lat = 37.4908266,
    .lon = 15.0073063,
    .radius = 200
};
  */
  #endif /* __GPS_GEOFENCE_CFG_DATA_H__ */