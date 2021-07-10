#include "../DuckLink.h"

int DuckLink::setupWithDefaults(std::vector<byte> deviceId, String ssid,
                                String password) {
  int err = Duck::setupWithDefaults(deviceId, ssid, password);
  if (err != DUCK_ERR_NONE) {
    logerr("ERROR setupWithDefaults rc = " + String(err));
    return err;
  }

  err = setupRadio();
  if (err != DUCK_ERR_NONE) {
    logerr("ERROR setupWithDefaults rc = " + String(err));
    return err;
  }
  
  err = setupWifi("DuckLink");
  if (err != DUCK_ERR_NONE) {
    logerr("ERROR setupWithDefaults rc = " + String(err));
    return err;
  }

  err = setupDns();
  if (err != DUCK_ERR_NONE) {
    logerr("ERROR setupWithDefaults rc = " + String(err));
    return err;
  }

  err = setupWebServer(true);
  if (err != DUCK_ERR_NONE) {
    logerr("ERROR setupWithDefaults rc = " + String(err));
    return err;
  }

  err = setupOTA();
  if (err != DUCK_ERR_NONE) {
    logerr("ERROR setupWithDefaults rc = " + String(err));
    return err;
  }
  
  loginfo("DuckLink setup done");
  return DUCK_ERR_NONE;
}

void DuckLink::handleReceivedPacket() {
    loginfo("handleReceivedPacket()...");

    std::vector<byte> data;
    //int err = duckRadio->readReceivedData(&data);
    data = DuckRadio::getLastRxPacket();
    //if (err != DUCK_ERR_NONE) {
    //  logerr("ERROR Failed to get data from DuckRadio. rc = " + String(err));
    //  return;
    //}
    CdpPacket packet = CdpPacket(data);
    if (packet.dduid == this->duid) {
      loginfo("Got a packet. Invoke callback");
      recvDataCallback(data);
    } else {
      loginfo("Packet is not addressed to us. Ignoring it...");
    }
}

void DuckLink::run() {
  duckRadio->processRadioIrq();
  handleOtaUpdate();
  if (DuckRadio::getReceiveFlag()) {
    duckutils::setInterrupt(false);
    DuckRadio::setReceiveFlag(false);

    handleReceivedPacket();
    rxPacket->reset();

    duckutils::setInterrupt(true);
    //startReceive();
  }
  processPortalRequest();
}
