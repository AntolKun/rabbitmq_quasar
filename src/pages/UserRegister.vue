<template>
  <q-page class="flex flex-center">
    <q-card>
      <q-card-section>
        <div class="text-h6">Register</div>
      </q-card-section>
      <q-card-section>
        <q-form @submit="register" @reset.prevent>
          <q-input v-model="nama" label="Nama" />
          <q-input v-model="email" label="Email" type="email" />
          <q-input v-model="password" label="Password" type="password" />
          <q-btn type="submit" label="Register" color="primary" />
        </q-form>
      </q-card-section>
    </q-card>
  </q-page>
</template>

<script>
import axios from 'axios';

export default {
  name: 'UserRegister',
  data() {
    return {
      nama: '',
      email: '',
      password: ''
    };
  },
  methods: {
    async register() {
      try {
        const response = await axios.post('http://localhost:7000/register', {
          nama: this.nama,
          email: this.email,
          password: this.password
        });
        this.$q.notify({ type: 'positive', message: response.data.message });
        this.$router.push('/login');
      } catch (error) {
        this.$q.notify({ type: 'negative', message: error.response?.data?.message || 'Registration failed' });
      }
    }
  }
};
</script>
