<template>
  <div class="q-pa-md">
    <div class="q-gutter-md" style="max-width: 1500px">
      <q-input filled type="textarea" rows="30" readonly v-model="message" />
    </div>
  </div>
</template>

<script>
import { ref } from "vue";
import * as mqtt from "mqtt/dist/mqtt.min";

export default {
  data() {
    return {
      message: "",
    };
  },

  created() {
    const opt = {
      username: "/iot:kelas_edp",
      password: "kelas_edp",
      clientId: "tolobrutal",
      protocolId: "MQTT",
    };

    const client = mqtt.connect("ws://103.167.112.188:15675/ws", opt);
    client.on("connect", () => {
      this.message = "Okeh sip, konek bos \n";
    });
    client.stream.on("error", function (err) {
      if (err) {
        console.log("ini ngeleg ini");
      }
    });
    client.on("connect", function () {
      client.subscribe("tolo-arif", function () {
        client.publish(
          "tolo-arif",
          `CINTAI USUSMU LIHAT TOLO TIAP HARI (INI DARI WEB) ${new Date().toString()}`
        );
      });
    });
    client.stream.on("error", function (err) {
      if (err) {
        console.log("ini ngeleg banget");
      }
    });
    client.on("connect", function () {});
    client.subscribe("tolo-arif");
    client.on("message", (topic, message) => {
      console.log(message.toString());

      this.message += `${message.toString()} \n`;
    });
  },
};
</script>
