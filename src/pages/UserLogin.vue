<template>
  <q-page class="flex flex-center">
    <q-card>
      <q-card-section>
        <div class="text-h6">Login</div>
      </q-card-section>
      <q-card-section>
        <q-form @submit="login">
          <q-input v-model="email" label="Email" type="email" />
          <q-input v-model="password" label="Password" type="password" />
          <q-btn type="submit" label="Login" color="primary" />
        </q-form>
      </q-card-section>
    </q-card>
  </q-page>
</template>

<script>
import axios from 'axios';

export default {
  name: 'UserLogin',
  data() {
    return {
      email: '',
      password: ''
    };
  },
  methods: {
    async login() {
      try {
        const response = await axios.post('http://localhost:7000/login', {
          email: this.email,
          password: this.password
        });
        this.$q.notify({ type: 'positive', message: response.data.message });
        this.$router.push('/');
      } catch (error) {
        this.$q.notify({ type: 'negative', message: error.response.data.message || 'Login failed' });
      }
    }
  }
};
</script>
