<template>
  <q-layout>
    <q-page-container>
      <q-page class="flex bg-image flex-center bg-red-4">
        <q-card
          style="border-radius: 10%"
          v-bind:style="$q.screen.lt.sm ? { width: '80%' } : { width: '30%' }"
        >
          <q-card-section>
            <q-avatar size="105px" class="absolute-center shadow-10">
              <img src="~assets/images/Laravel.svg" alt="Logo" />
            </q-avatar>
          </q-card-section>
          <q-card-section>
            <div class="text-center q-pt-lg">
              <div class="col text-h5 q-mt-md text-bold">Register Akun</div>
            </div>
          </q-card-section>
          <q-card-section>
            <q-form @submit.prevent="register" class="q-gutter-md">
              <q-input
                color="grey-9"
                filled
                v-model="nama"
                type="text"
                label="Nama"
              >
                <template v-slot:prepend>
                  <q-icon name="person_add" color="grey-8" />
                </template>
              </q-input>
              <q-input
                color="grey-9"
                filled
                v-model="email"
                type="email"
                label="Email"
              >
                <template v-slot:prepend>
                  <q-icon name="email" color="grey-8" />
                </template>
              </q-input>
              <q-input
                color="grey-9"
                filled
                v-model="password"
                type="password"
                label="Password"
              >
                <template v-slot:prepend>
                  <q-icon name="lock" color="grey-8" />
                </template>
              </q-input>
              <div class="flex flex-center">
                <q-btn
                  type="submit"
                  unelevated
                  rounded
                  class="q-mt-xs"
                  color="grey-9"
                  label="Masuk"
                  style="width: 90%"
                />
              </div>
              <div class="flex flex-center" style="font-size: 17px">
                Sudah punya akun?
                <q-btn
                  flat
                  rounded
                  color="teal-8"
                  label="Login"
                  style="width: 16%; font-weight: bold"
                  to="/"
                ></q-btn>
              </div>
            </q-form>
          </q-card-section>
        </q-card>
      </q-page>
    </q-page-container>
  </q-layout>
</template>

<script>
import axios from "axios";

export default {
  name: "UserRegister",
  data() {
    return {
      nama: "",
      email: "",
      password: "",
    };
  },
  methods: {
    async register() {
      try {
        const response = await axios.post("http://localhost:7000/register", {
          nama: this.nama,
          email: this.email,
          password: this.password,
        });
        this.$q.notify({ type: "positive", message: response.data.message });
        this.$router.push("/");
      } catch (error) {
        this.$q.notify({
          type: "negative",
          message: error.response?.data?.message || "Registration failed",
        });
      }
    },
  },
};
</script>
